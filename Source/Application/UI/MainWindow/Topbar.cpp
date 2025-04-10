#include "Topbar.hpp"

namespace UI {

void Topbar::render() {
    ImGui::BeginMainMenuBar();
    ImGui::SetWindowSize(ImVec2(0, 100));
    if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("New")) {
            // Handle new file action
        }
        if (ImGui::MenuItem("Open")) {
            // Handle open file action
        }
        if (ImGui::MenuItem("Save")) {
            // Handle save file action
        }
        if (ImGui::MenuItem("Save As")) {
            // Handle save as action
        }
        if (ImGui::MenuItem("Exit")) {
            // Handle exit action
            glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
        }
        ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Edit")) {
        if (ImGui::MenuItem("Undo")) {
            // Handle undo action
        }
        if (ImGui::MenuItem("Redo")) {
            // Handle redo action
        }
        ImGui::EndMenu();
    }

   if (ImGui::MenuItem("Preferences")) {
        // Handle preferences action
    }

    ImGui::EndMainMenuBar();
}

} // namespace UI