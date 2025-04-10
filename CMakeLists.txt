cmake_minimum_required(VERSION 3.10)

project(Setuav CXX)

# Set global output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

# Set Library directories
set(ImGui_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/imgui")

# Handle platform-specific paths for OpenCASCADE
if(WIN32)
    set(glfw3_DIR "C:/Dev/Tools/vcpkg/installed/x64-windows/share/glfw3")
else()
    find_package(OpenGL REQUIRED)
endif()

find_package(glfw3 REQUIRED)

# Add ImGui library
add_library(imgui STATIC
    ${ImGui_DIR}/imgui.cpp
    ${ImGui_DIR}/imgui_draw.cpp
    ${ImGui_DIR}/imgui_demo.cpp
    ${ImGui_DIR}/imgui_tables.cpp
    ${ImGui_DIR}/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC ${ImGui_DIR})

# Add ImGui backend library for GLFW and OpenGL
add_library(imgui_backend STATIC
    ${ImGui_DIR}/backends/imgui_impl_glfw.cpp
    ${ImGui_DIR}/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui_backend PUBLIC
    ${ImGui_DIR}
    ${ImGui_DIR}/backends
)

include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})

add_subdirectory(Source/Core)