#include "MainWindow.hpp"
#include <iostream>

namespace UI {

MainWindow::MainWindow(GLFWwindow *window, Geometry::Editor *geometryEditor)
    : mWindow(window),
      mTopbar(new Topbar()),
      mSidebar(new Sidebar(geometryEditor))
{
}

MainWindow::~MainWindow()
{
    cleanup();
    delete mTopbar;
    delete mSidebar;
}

void MainWindow::init()
{    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& aIO = ImGui::GetIO();
    // aIO.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    
    // Check if OpenGL context is valid
    if (!mWindow) {
        std::cerr << "Error: GLFW window is null during UI initialization" << std::endl;
        return;
    }

    // Make sure the correct context is current
    glfwMakeContextCurrent(mWindow);
    
    // Initialize ImGui backends with explicit specification of GL version
    ImGui_ImplGlfw_InitForOpenGL(mWindow, true);
    const char* glsl_version = "#version 330 core";
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Setup Dear ImGui style.
    // ImGui::StyleColorsClassic();
}

void MainWindow::render()
{
    // Ensure the correct OpenGL context is current
    glfwMakeContextCurrent(mWindow);
    
    // Begin new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (mTopbar)
        mTopbar->render();
    if (mSidebar)
        mSidebar->render();

    // End frame and render
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void MainWindow::cleanup()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

} // namespace UI