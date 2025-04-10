#include "ApplicationWindow.hpp"

#if defined (__APPLE__)
#undef Handle // avoid name collisions in macOS headers
#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_NSGL
#elif defined (_WIN32)
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#else
#define GLFW_EXPOSE_NATIVE_X11
#define GLFW_EXPOSE_NATIVE_GLX
#endif

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <iostream>

ApplicationWindow::ApplicationWindow(int theWidth, int theHeight, const TCollection_AsciiString& theTitle)
    : myGlfwWindow(nullptr),
    myXLeft(0),
    myYTop(0),
    myXRight(0),
    myYBottom(0)
{
    // Set OpenGL version before creating window (especially important for Linux)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    myGlfwWindow = glfwCreateWindow(theWidth, theHeight, theTitle.ToCString(), NULL, NULL);
    
    if (myGlfwWindow == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent(myGlfwWindow);
    
    // Get window position and size
    int aWidth = 0, aHeight = 0;
    glfwGetWindowPos(myGlfwWindow, &myXLeft, &myYTop);
    glfwGetWindowSize(myGlfwWindow, &aWidth, &aHeight);
    myXRight = myXLeft + aWidth;
    myYBottom = myYTop + aHeight;

#if !defined(_WIN32) && !defined(__APPLE__)
    myDisplay = new Aspect_DisplayConnection((Aspect_XDisplay*)glfwGetX11Display());
#endif
}

void ApplicationWindow::Close()
{
    if (myGlfwWindow != nullptr)
    {
        glfwDestroyWindow(myGlfwWindow);
        myGlfwWindow = nullptr;
    }
}

Aspect_Drawable ApplicationWindow::NativeHandle() const
{
#if defined (__APPLE__)
    return (Aspect_Drawable)glfwGetCocoaWindow(myGlfwWindow);
#elif defined (_WIN32)
    return (Aspect_Drawable)glfwGetWin32Window(myGlfwWindow);
#else
    return (Aspect_Drawable)glfwGetX11Window(myGlfwWindow);
#endif
}

Aspect_RenderingContext ApplicationWindow::NativeGlContext() const
{
#if defined (__APPLE__)
    return (NSOpenGLContext*)glfwGetNSGLContext(myGlfwWindow);
#elif defined (_WIN32)
    return glfwGetWGLContext(myGlfwWindow);
#else
    return glfwGetGLXContext(myGlfwWindow);
#endif
}

Standard_Boolean ApplicationWindow::IsMapped() const
{
    return glfwGetWindowAttrib(myGlfwWindow, GLFW_VISIBLE) != 0;
}

void ApplicationWindow::Map() const
{
    glfwShowWindow(myGlfwWindow);
}

void ApplicationWindow::Unmap() const
{
    glfwHideWindow(myGlfwWindow);
}

Aspect_TypeOfResize ApplicationWindow::DoResize()
{
    if (glfwGetWindowAttrib(myGlfwWindow, GLFW_VISIBLE) == 1)
    {
        int anXPos = 0, anYPos = 0, aWidth = 0, aHeight = 0;
        glfwGetWindowPos(myGlfwWindow, &anXPos, &anYPos);
        glfwGetWindowSize(myGlfwWindow, &aWidth, &aHeight);
        myXLeft = anXPos;
        myXRight = anXPos + aWidth;
        myYTop = anYPos;
        myYBottom = anYPos + aHeight;
    }
    return Aspect_TOR_UNKNOWN;
}

Graphic3d_Vec2i ApplicationWindow::CursorPosition() const
{
    Graphic3d_Vec2d aPos;
    glfwGetCursorPos(myGlfwWindow, &aPos.x(), &aPos.y());
    return Graphic3d_Vec2i((int)aPos.x(), (int)aPos.y());
}