# Application CMakeLists.txt

set(GEOM_SOURCES
    Geometry/Geom_Viewer.cpp
    Geometry/Geom_Viewer.hpp
    Geometry/Geom_Editor.cpp
    Geometry/Geom_Editor.hpp
)

set(APPLICATION_SOURCES
    Setuav.cpp
    Setuav.hpp
    ApplicationWindow.cpp
    ApplicationWindow.hpp
    UI/MainWindow/MainWindow.cpp
    UI/MainWindow/MainWindow.hpp
    UI/MainWindow/Sidebar.cpp
    UI/MainWindow/Sidebar.hpp
    UI/MainWindow/Topbar.cpp
    UI/MainWindow/Topbar.hpp
    UI/MainWindow/AirframeMenu.cpp
    UI/MainWindow/AirframeMenu.hpp
    UI/MainWindow/PropulsionMenu.cpp
    UI/MainWindow/PropulsionMenu.hpp
    UI/MainWindow/PerformanceMenu.cpp
    UI/MainWindow/PerformanceMenu.hpp
)

# Create Application executable
add_executable(Setuav
    main.cpp
    ${APPLICATION_SOURCES}
    ${GEOM_SOURCES}
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

if(WIN32)
    # Windows-specific libraries would go here
else()
    target_link_libraries(Setuav ${OPENGL_LIBRARIES})
endif()

# Link OpenCASCADE libraries
foreach(LIB ${OpenCASCADE_LIBRARIES})
    if(WIN32)
        target_link_libraries(Setuav debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
        target_link_libraries(Setuav optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
    else()
        target_link_libraries(Setuav ${OpenCASCADE_LIBRARY_DIR}/lib${LIB}.so)
    endif()
endforeach()
