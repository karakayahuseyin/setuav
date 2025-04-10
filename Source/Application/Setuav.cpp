#include "Setuav.hpp"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

Setuav::Setuav() {}

Setuav::~Setuav() {}

void Setuav::run()
{
    initWindow(1280, 720, "Setuav");
    initGeometryViewer();
    initMainWindow();
    mainloop();
    cleanup();
}

void Setuav::initWindow(int width, int height, const char* title)
{
    glfwSetErrorCallback(Viewer::errorCallback);
    glfwInit();
    const bool useCoreProfile = true;
    if (useCoreProfile)
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
    mWindow = new ApplicationWindow(width, height, title);
    // Don't set window user pointer here - it will be set in initViewer
}

void Setuav::initGeometryViewer()
{
    mGeometryViewer = new Viewer(mWindow);
    mGeometryViewer->init();
    
    glfwSetWindowUserPointer(mWindow->getGlfwWindow(), mGeometryViewer);
    glfwSetWindowSizeCallback(mWindow->getGlfwWindow(), Viewer::onResizeCallback);
    glfwSetFramebufferSizeCallback(mWindow->getGlfwWindow(), Viewer::onFBResizeCallback);
}

void Setuav::initMainWindow()
{
    mMainWindow = new MainWindow(mWindow->getGlfwWindow(), new Editor(mGeometryViewer->getContext(), mGeometryViewer->getView()));
    mMainWindow->init();
}

void Setuav::mainloop()
{
    while (!glfwWindowShouldClose(mWindow->getGlfwWindow()))
    {
        // Always poll events regardless of which page we're on
        glfwPollEvents();
        
        // Make sure we render in the correct order
        if (mMainWindow->getCurrentPage() != Sidebar::Page::Performance)
        {
            mGeometryViewer->render();
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
        
        mMainWindow->render();
        
        // Only swap buffers if window is still valid
        if (!mWindow.IsNull() && mWindow->getGlfwWindow() != nullptr)
        {
            glfwSwapBuffers(mWindow->getGlfwWindow());
        }
    }
}

void Setuav::cleanup()
{
    if (mMainWindow != nullptr)
    {
        delete mMainWindow;
        mMainWindow = nullptr;
    }
    
    if (mGeometryViewer != nullptr)
    {
        mGeometryViewer->cleanup();
        delete mGeometryViewer;
        mGeometryViewer = nullptr;
    }
    
    // The mWindow handle will be nullified inside Viewer::cleanup
}
