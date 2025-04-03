#include "Setuav.hpp"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

Setuav::Setuav() {}

Setuav::~Setuav() {}

void Setuav::run()
{
    initWindow(1280, 720, "Setuav");
    initOcctView();
    initGui();
    mainloop();
    cleanup();
}

void Setuav::initWindow(int theWidth, int theHeight, const char* theTitle)
{
    glfwSetErrorCallback(OcctView::errorCallback);
    glfwInit();
    const bool toAskCoreProfile = true;
    if (toAskCoreProfile)
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#if defined (__APPLE__)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        //glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);
        //glfwWindowHint(GLFW_DECORATED, GL_FALSE);
    }
    mWindow = new Window(theWidth, theHeight, theTitle);
    // Don't set window user pointer here - it will be set in initOcctView
}

void Setuav::initOcctView()
{
    mOcctView = new OcctView(mWindow);
    mOcctView->init();
    
    glfwSetWindowUserPointer(mWindow->getGlfwWindow(), mOcctView);
    glfwSetWindowSizeCallback(mWindow->getGlfwWindow(), OcctView::onResizeCallback);
    glfwSetFramebufferSizeCallback(mWindow->getGlfwWindow(), OcctView::onFBResizeCallback);
    glfwSetScrollCallback(mWindow->getGlfwWindow(), OcctView::onMouseScrollCallback);
    glfwSetMouseButtonCallback(mWindow->getGlfwWindow(), OcctView::onMouseButtonCallback);
    glfwSetCursorPosCallback(mWindow->getGlfwWindow(), OcctView::onMouseMoveCallback);
}

void Setuav::initGui()
{
    mGui = new Gui(mWindow->getGlfwWindow(), new Geometry(mOcctView->getContext(), mOcctView->getView()));
    mGui->init();
}

void Setuav::mainloop()
{
    while (!glfwWindowShouldClose(mWindow->getGlfwWindow()))
    {
        // Always poll events regardless of which page we're on
        glfwPollEvents();
        
        // Make sure we render in the correct order
        if (mGui->getCurrentPage() != Sidebar::Page::Performance)
        {
            mOcctView->render();
            // disable IO for ImGui to avoid capturing mouse events
        } 
        else 
        {
            // When on Performance page, we still need to:
            // 1. Make sure window is active for rendering
            glfwMakeContextCurrent(mWindow->getGlfwWindow());
            
            // 2. Clear the frame buffer
            int width, height;
            glfwGetFramebufferSize(mWindow->getGlfwWindow(), &width, &height);
            glViewport(0, 0, width, height);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
        
        mGui->render();
        
        // Only swap buffers if window is still valid
        if (!mWindow.IsNull() && mWindow->getGlfwWindow() != nullptr)
        {
            glfwSwapBuffers(mWindow->getGlfwWindow());
        }
    }
}

void Setuav::cleanup()
{
    if (mGui != nullptr)
    {
        delete mGui;
        mGui = nullptr;
    }
    
    if (mOcctView != nullptr)
    {
        mOcctView->cleanup();
        delete mOcctView;
        mOcctView = nullptr;
    }
    
    // The mWindow handle will be nullified inside OcctView::cleanup
}
