cmake_minimum_required(VERSION 3.10)

project(Setuav CXX)

set(OpenCASCADE_DIR "C:/Dev/Libraries/OpenCASCADE/occt-vc143-64/cmake")
set(glfw3_DIR "C:/Dev/Tools/vcpkg/installed/x64-windows/share/glfw3")

find_package(OpenCASCADE REQUIRED)
find_package(glfw3 REQUIRED)

# ImGui library
add_library(imgui STATIC
    Source/Lib/imgui/imgui.cpp
    Source/Lib/imgui/imgui_draw.cpp
    Source/Lib/imgui/imgui_demo.cpp
    Source/Lib/imgui/imgui_tables.cpp
    Source/Lib/imgui/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC Source/Lib/imgui)

# ImGui backend
add_library(imgui_backend STATIC
    Source/Lib/imgui/backends/imgui_impl_glfw.cpp
    Source/Lib/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui_backend PUBLIC
    Source/Lib/imgui
    Source/Lib/imgui/backends
)

include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})

set(SOURCES
    Source/Application/Setuav.cpp
    Source/Application/Setuav.hpp
    Source/Application/Window.cpp
    Source/Application/Window.hpp
    Source/Application/Geometry/Viewer.cpp
    Source/Application/Geometry/Viewer.hpp
    Source/Application/Geometry/Editor.cpp
    Source/Application/Geometry/Editor.hpp
    Source/Application/UI/MainWindow/MainWindow.cpp
    Source/Application/UI/MainWindow/MainWindow.hpp
    Source/Application/UI/MainWindow/Sidebar.cpp
    Source/Application/UI/MainWindow/Sidebar.hpp
    Source/Application/UI/MainWindow/Topbar.cpp
    Source/Application/UI/MainWindow/Topbar.hpp
)

add_executable(Setuav
    Source/Application/main.cpp
    ${SOURCES}
)

target_include_directories(Setuav PRIVATE 
    Source/Lib/imgui
    Source/Lib/imgui/backends
)

target_link_libraries(Setuav imgui glfw imgui_backend)

foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(Setuav debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
    target_link_libraries(Setuav optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()