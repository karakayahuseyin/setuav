cmake_minimum_required(VERSION 3.10)

project(Setuav CXX)

set(OpenCASCADE_DIR "C:/Dev/Libraries/OpenCASCADE/occt-vc143-64/cmake")
set(glfw3_DIR "C:/Dev/Tools/vcpkg/installed/x64-windows/share/glfw3")

find_package(OpenCASCADE REQUIRED)
find_package(glfw3 REQUIRED)

# ImGui library
add_library(imgui STATIC
    lib/imgui/imgui.cpp
    lib/imgui/imgui_draw.cpp
    lib/imgui/imgui_demo.cpp
    lib/imgui/imgui_tables.cpp
    lib/imgui/imgui_widgets.cpp
)

target_include_directories(imgui PUBLIC lib/imgui)

# ImGui backend
add_library(imgui_backend STATIC
    lib/imgui/backends/imgui_impl_glfw.cpp
    lib/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui_backend PUBLIC
    lib/imgui
    lib/imgui/backends
)

include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})

add_executable(Setuav
    src/main.cpp
    src/App/OcctView.cpp
    src/App/OcctView.hpp
    src/App/Window.cpp
    src/App/Window.hpp
    src/App/Setuav.cpp
    src/App/Setuav.hpp
    src/App/gui/Gui.cpp
    src/App/gui/Gui.hpp
    src/App/gui/Sidebar.cpp
    src/App/gui/Sidebar.hpp
    src/App/gui/Topbar.cpp
    src/App/gui/Topbar.hpp
)

target_include_directories(Setuav PRIVATE 
    lib/imgui
    lib/imgui/backends
)

target_link_libraries(Setuav imgui glfw imgui_backend)

foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(Setuav debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
    target_link_libraries(Setuav optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()