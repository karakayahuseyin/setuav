#include "Geom_Viewer.hpp"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <Message.hxx>
#include <Message_Messenger.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <iostream>

#include <GLFW/glfw3.h>

//! Convert GLFW mouse button into Aspect_VKeyMouse.
static Aspect_VKeyMouse mouseButtonFromGlfw(int theButton)
{
    switch (theButton)
    {
    case GLFW_MOUSE_BUTTON_LEFT:   return Aspect_VKeyMouse_LeftButton;
    case GLFW_MOUSE_BUTTON_RIGHT:  return Aspect_VKeyMouse_RightButton;
    case GLFW_MOUSE_BUTTON_MIDDLE: return Aspect_VKeyMouse_MiddleButton;
    }
    return Aspect_VKeyMouse_NONE;
}

//! Convert GLFW key modifiers into Aspect_VKeyFlags.
static Aspect_VKeyFlags keyFlagsFromGlfw(int theFlags)
{
    Aspect_VKeyFlags aFlags = Aspect_VKeyFlags_NONE;
    if ((theFlags & GLFW_MOD_SHIFT) != 0)
    {
        aFlags |= Aspect_VKeyFlags_SHIFT;
    }
    if ((theFlags & GLFW_MOD_CONTROL) != 0)
    {
        aFlags |= Aspect_VKeyFlags_CTRL;
    }
    if ((theFlags & GLFW_MOD_ALT) != 0)
    {
        aFlags |= Aspect_VKeyFlags_ALT;
    }
    if ((theFlags & GLFW_MOD_SUPER) != 0)
    {
        aFlags |= Aspect_VKeyFlags_META;
    }
    return aFlags;
}

Geom_Viewer::Geom_Viewer(const Handle(ApplicationWindow)& theWindow)
    : mWindow(theWindow)
{
}

Geom_Viewer::~Geom_Viewer()
{
    // Make sure we're not accessing deleted objects in callbacks
    if (!mWindow.IsNull() && mWindow->getGlfwWindow() != nullptr) {
        glfwSetWindowSizeCallback(mWindow->getGlfwWindow(), nullptr);
        glfwSetFramebufferSizeCallback(mWindow->getGlfwWindow(), nullptr);
        glfwSetScrollCallback(mWindow->getGlfwWindow(), nullptr);
        glfwSetMouseButtonCallback(mWindow->getGlfwWindow(), nullptr);
        glfwSetCursorPosCallback(mWindow->getGlfwWindow(), nullptr);
    }
}

Geom_Viewer* Geom_Viewer::toView(GLFWwindow* theWin)
{
    return static_cast<Geom_Viewer*>(glfwGetWindowUserPointer(theWin));
}

void Geom_Viewer::errorCallback(int theError, const char* theDescription)
{
    Message::DefaultMessenger()->Send(TCollection_AsciiString("Error") + theError + 
                                      ": " + theDescription, Message_Fail);
}

void Geom_Viewer::init()
{
    if (mWindow.IsNull())
    {
        return;
    }

    Handle(OpenGl_GraphicDriver) aGraphicDriver
        = new OpenGl_GraphicDriver(mWindow->GetDisplay(), Standard_False);
    aGraphicDriver->SetBuffersNoSwap(Standard_True);

    Handle(V3d_Viewer) aViewer = new V3d_Viewer(aGraphicDriver);
    aViewer->SetDefaultLights();
    aViewer->SetLightOn();
    aViewer->SetDefaultTypeOfView(V3d_PERSPECTIVE);
    aViewer->ActivateGrid(Aspect_GT_Rectangular, Aspect_GDM_Lines);
    mView = aViewer->CreateView();
    //mView->SetImmediateUpdate(Standard_False);
    mView->SetWindow(mWindow, mWindow->NativeGlContext());
    mView->ChangeRenderingParams().ToShowStats = Standard_True;
    
    mContext = new AIS_InteractiveContext(aViewer);
    mView->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.08, V3d_WIREFRAME);
    mView->SetBackgroundColor(Quantity_NOC_GRAY25);
}

void Geom_Viewer::handleViewRedraw(const Handle(AIS_InteractiveContext)& theCtx,
    const Handle(V3d_View)& theView)
{
    AIS_ViewController::handleViewRedraw(theCtx, theView);
}

void Geom_Viewer::render()
{
    if (myToWaitEvents)
    {
        glfwWaitEvents();
    }
    else
    {
        glfwPollEvents();
    }
    if (!mView.IsNull() && !mContext.IsNull())
    {
        mView->InvalidateImmediate(); // redraw view even if it wasn't modified
        FlushViewEvents(mContext, mView, Standard_True);
    }
}

void Geom_Viewer::cleanup()
{
    // Clean up in proper order
    if (!mContext.IsNull())
    {
        mContext.Nullify();
    }
    
    if (!mView.IsNull())
    {
        mView->Remove();
        mView.Nullify();
    }
    
    if (!mWindow.IsNull())
    {
        mWindow->Close();
        mWindow.Nullify();
    }

    glfwTerminate();
}

void Geom_Viewer::onResize(int theWidth, int theHeight)
{
    if (theWidth != 0
        && theHeight != 0
        && !mView.IsNull())
    {
        mView->Window()->DoResize();
        mView->MustBeResized();
        mView->Invalidate();
        FlushViewEvents(mContext, mView, true);
    }
}

void Geom_Viewer::onMouseScroll(double theOffsetX, double theOffsetY)
{
    ImGuiIO& aIO = ImGui::GetIO();
    if (!mView.IsNull() && !aIO.WantCaptureMouse)
    {
        UpdateZoom(Aspect_ScrollDelta(mWindow->CursorPosition(), int(theOffsetY * 8.0)));
    }
}

void Geom_Viewer::onMouseButton(int theButton, int theAction, int theMods)
{
    ImGuiIO& aIO = ImGui::GetIO();
    if (mView.IsNull() || aIO.WantCaptureMouse)
    {
        return;
    }
    
    const Graphic3d_Vec2i aPos = mWindow->CursorPosition();
    if (theAction == GLFW_PRESS)
    {
        PressMouseButton(aPos, mouseButtonFromGlfw(theButton), keyFlagsFromGlfw(theMods), false);
    }
    else
    {
        ReleaseMouseButton(aPos, mouseButtonFromGlfw(theButton), keyFlagsFromGlfw(theMods), false);
    }
}

void Geom_Viewer::onMouseMove(int thePosX, int thePosY)
{
    if (mView.IsNull())
    {
        return;
    }

    ImGuiIO& aIO = ImGui::GetIO();
    if (aIO.WantCaptureMouse)
    {
        //mView->Redraw();
    }
    else
    {
        const Graphic3d_Vec2i aNewPos(thePosX, thePosY);
        UpdateMousePosition(aNewPos, PressedMouseButtons(), LastMouseFlags(), Standard_False);
    }
}