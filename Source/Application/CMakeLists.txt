# Application CMakeLists.txt

set(APPLICATION_SOURCES
    Setuav.cpp
    Setuav.hpp
    Window.cpp
    Window.hpp
    Geometry/Viewer.cpp
    Geometry/Viewer.hpp
    Geometry/Editor.cpp
    Geometry/Editor.hpp
    UI/MainWindow/MainWindow.cpp
    UI/MainWindow/MainWindow.hpp
    UI/MainWindow/Sidebar.cpp
    UI/MainWindow/Sidebar.hpp
    UI/MainWindow/Topbar.cpp
    UI/MainWindow/Topbar.hpp
)

# Create Application executable
add_executable(Setuav
    main.cpp
    ${APPLICATION_SOURCES}
)

# Include directories
target_include_directories(Setuav PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/Source/Core
    ${ImGui_DIR}
    ${ImGui_DIR}/backends
)

# Link libraries to the application
target_link_libraries(Setuav 
    Core
    imgui
    imgui_backend
    glfw
)

# Link OpenCASCADE libraries
foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(Setuav debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
    target_link_libraries(Setuav optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()
