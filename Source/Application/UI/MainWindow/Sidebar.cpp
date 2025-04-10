#include "Sidebar.hpp"

#include <GLFW/glfw3.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <iostream>

Sidebar::Sidebar(Geom_Editor *geometryEditor)
    : mGeometryEditor(geometryEditor),
      mAirframeMenu(std::make_unique<AirframeMenu>()),
      mPropulsionMenu(std::make_unique<PropulsionMenu>()),
      mPerformanceMenu(std::make_unique<PerformanceMenu>())
{
}

void Sidebar::render() {
    renderPageSelector();
    renderPageMenu();
}

void Sidebar::renderPageSelector() {
    // Calculate window position and size
    float windowWidth = 300.0f;
    float buttonSize = 30.0f;
    float windowPadding = 10.0f; // Padding inside the window
    float windowHeight = buttonSize + windowPadding * 2;
    
    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    // Get the height of the main menu bar
    float menuBarHeight = ImGui::GetFrameHeight();
    ImVec2 windowPos(displaySize.x - windowWidth, menuBarHeight);
    
    // Set window position and properties
    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize(ImVec2(windowWidth, windowHeight));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(windowPadding, windowPadding));
    ImGui::Begin("Page Selector", nullptr, 
        ImGuiWindowFlags_NoTitleBar | 
        ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoCollapse);
    
    // Set the square size for buttons
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(buttonSize/4, buttonSize/4));
    
    // Airframe button - Blue color
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.4f, 0.8f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.5f, 0.9f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.3f, 0.7f, 1.0f));
    if (ImGui::Button("##Airframe", ImVec2(buttonSize, buttonSize))) {
        mCurrentPage = Page::Airframe;
    }
    // For future icon implementation:
    // ImGui::PushFont(iconFont);
    // if (ImGui::Button(ICON_FA_PLANE "##Airframe", ImVec2(buttonSize, buttonSize))) {
    //     mCurrentPage = Page::Airframe;
    // }
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);
    
    ImGui::SameLine();
    
    // Propulsion button - Red color
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.2f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.3f, 0.3f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.7f, 0.1f, 0.1f, 1.0f));
    if (ImGui::Button("##Propulsion", ImVec2(buttonSize, buttonSize))) {
        mCurrentPage = Page::Propulsion;
    }
    // For future icon implementation:
    // ImGui::PushFont(iconFont);
    // if (ImGui::Button(ICON_FA_ROCKET "##Propulsion", ImVec2(buttonSize, buttonSize))) {
    //     mCurrentPage = Page::Propulsion;
    // }
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);
    
    ImGui::SameLine();
    
    // Performance button - Green color
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.2f, 0.8f, 0.2f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.3f, 0.9f, 0.3f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.1f, 0.7f, 0.1f, 1.0f));
    if (ImGui::Button("##Performance", ImVec2(buttonSize, buttonSize))) {
        mCurrentPage = Page::Performance;
    }
    // For future icon implementation:
    // ImGui::PushFont(iconFont);
    // if (ImGui::Button(ICON_FA_CHART_LINE "##Performance", ImVec2(buttonSize, buttonSize))) {
    //     mCurrentPage = Page::Performance;
    // }
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);
    
    ImGui::PopStyleVar();
    
    ImGui::PopStyleVar();
    ImGui::End();
}

void Sidebar::renderPageMenu() {
    // Calculate window position and size
    float windowWidth = 300.0f;
    float buttonSize = 30.0f;
    float windowPadding = 10.0f; // Padding inside the window
    float topWindowHeight = buttonSize + windowPadding * 2;
    
    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    // Get the height of the main menu bar
    float menuBarHeight = ImGui::GetFrameHeight();
    ImVec2 windowPos(displaySize.x - windowWidth, menuBarHeight + topWindowHeight);
    ImVec2 windowSize(windowWidth, displaySize.y - menuBarHeight - topWindowHeight);
    
    // Set window position and properties
    ImGui::SetNextWindowPos(windowPos);
    ImGui::SetNextWindowSize(windowSize);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(windowPadding, windowPadding));
    ImGui::Begin("Page Menu", nullptr, 
        ImGuiWindowFlags_NoTitleBar | 
        ImGuiWindowFlags_NoResize | 
        ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoCollapse);

    switch (mCurrentPage) {
        case Page::Airframe:
            mAirframeMenu->render();
            break;
        case Page::Propulsion:
            mPropulsionMenu->render();
            break;
        case Page::Performance:
            mPerformanceMenu->render();
            break;
        default:
            std::cerr << "Unknown page type!" << std::endl;
            break;
    }

    ImGui::PopStyleVar();
    ImGui::End();
}