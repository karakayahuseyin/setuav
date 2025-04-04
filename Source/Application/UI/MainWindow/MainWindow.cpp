#include "MainWindow.hpp"

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

    ImGui_ImplGlfw_InitForOpenGL(mWindow, Standard_True);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Setup Dear ImGui style.
    // ImGui::StyleColorsClassic();
}

void MainWindow::render()
{
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