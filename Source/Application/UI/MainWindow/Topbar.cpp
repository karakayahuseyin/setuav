#include "Topbar.hpp"

namespace UI {

void Topbar::render() {
    ImGui::BeginMainMenuBar();
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Exit")) {
            glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
        }
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Edit")) {
        ImGui::MenuItem("Undo", NULL, false);
        ImGui::MenuItem("Redo", NULL, false);
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("View")) {
        ImGui::MenuItem("Sidebar", NULL, true);
        ImGui::EndMenu();
    }
    if (ImGui::BeginMenu("Help")) {
        ImGui::MenuItem("About", NULL, false);
        ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
}

} // namespace UI