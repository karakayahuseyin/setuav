cmake_minimum_required(VERSION 3.10)

project(Setuav CXX)

# Set Library directories
set(ImGui_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/imgui")
set(OpenCASCADE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/OpenCASCADE/occt-vc143-64")
set(glfw3_DIR "C:/Dev/Tools/vcpkg/installed/x64-windows/share/glfw3")

# Find packages
find_package(OpenCASCADE REQUIRED)
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

# Set Application sources
set(APPLICATION_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Application")
set(APPLICATION_SOURCES
    ${APPLICATION_SOURCE_DIR}/Setuav.cpp
    ${APPLICATION_SOURCE_DIR}/Setuav.hpp
    ${APPLICATION_SOURCE_DIR}/Window.cpp
    ${APPLICATION_SOURCE_DIR}/Window.hpp
    ${APPLICATION_SOURCE_DIR}/Geometry/Viewer.cpp
    ${APPLICATION_SOURCE_DIR}/Geometry/Viewer.hpp
    ${APPLICATION_SOURCE_DIR}/Geometry/Editor.cpp
    ${APPLICATION_SOURCE_DIR}/Geometry/Editor.hpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/MainWindow.cpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/MainWindow.hpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/Sidebar.cpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/Sidebar.hpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/Topbar.cpp
    ${APPLICATION_SOURCE_DIR}/UI/MainWindow/Topbar.hpp
)

# Create Application executable
add_executable(Setuav
    ${APPLICATION_SOURCE_DIR}/main.cpp
    ${APPLICATION_SOURCES}
)

# Link libraries to the application
target_include_directories(Setuav PRIVATE 
    ${ImGui_DIR}
    ${ImGui_DIR}/backends
)

target_link_libraries(Setuav imgui glfw imgui_backend)

foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(Setuav debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
    target_link_libraries(Setuav optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()