cmake_minimum_required(VERSION 3.10)

project(Setuav CXX)

# Configure RPATH for Linux
if(UNIX AND NOT APPLE)
    # Use RPATH instead of RUNPATH
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags")
    
    # Always use full RPATH
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    
    # Add the OpenCASCADE library directory to RPATH
    set(CMAKE_INSTALL_RPATH "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/OpenCASCADE/install/lib")
endif()

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
    set(OpenCASCADE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/OpenCASCADE/occt-vc143-64/cmake")
    set(glfw3_DIR "C:/Dev/Tools/vcpkg/installed/x64-windows/share/glfw3")
else()
    set(OpenCASCADE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source/Lib/OpenCASCADE/install/lib/cmake/opencascade")
    # For Linux, find system GLFW3
    find_package(OpenGL REQUIRED)
endif()

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

# Add subdirectories for Core and Application
add_subdirectory(Source/Core)
add_subdirectory(Source/Application)