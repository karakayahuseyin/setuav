#include "Sidebar.hpp"

#include <iostream>

void Sidebar::render() {
    // Set window position to the right side of the screen
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    float sidebarWidth = 300.0f;
    ImGui::SetNextWindowPos(ImVec2(viewport->WorkPos.x + viewport->WorkSize.x - sidebarWidth, viewport->WorkPos.y));
    ImGui::SetNextWindowSize(ImVec2(sidebarWidth, viewport->WorkSize.y));
    
    // Remove window decorations and make it fixed size
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | 
                                    ImGuiWindowFlags_NoResize | 
                                    ImGuiWindowFlags_NoCollapse |
                                    ImGuiWindowFlags_NoTitleBar;
                                    
    ImGui::Begin("Sidebar", nullptr, window_flags);
    
    // Calculate button width for side-by-side buttons (half of available width minus spacing)
    float availWidth = ImGui::GetContentRegionAvail().x;
    float buttonWidth = (availWidth - 2.0f * ImGui::GetStyle().ItemSpacing.x) / 3.0f;
    
    // First row: Airframe and Propulsion buttons side by side with equal width
    if(ImGui::Button("Airframe", ImVec2(buttonWidth, 0))) {
        mCurrentPage = Page::Airframe;
    }
    ImGui::SameLine();
    if(ImGui::Button("Propulsion", ImVec2(buttonWidth, 0))) {
        mCurrentPage = Page::Propulsion;
    }
    ImGui::SameLine();
    if(ImGui::Button("Performance", ImVec2(buttonWidth, 0))) {
        mCurrentPage = Page::Performance;
    }
    
    ImGui::End();
}