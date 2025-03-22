cmake_minimum_required(VERSION 3.10)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

project(
    setuav 
    VERSION ${VERSION}
    DESCRIPTION "SETUAV is a tool for UAV design and performance analysis "
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt Setup
set(QT_VERSION 6)
set(REQUIRED_QT_VERSION 6.5)

find_package(Qt${QT_VERSION} ${REQUIRED_QT_VERSION} REQUIRED 
    COMPONENTS 
        Quick 
        Core 
        Gui 
        Qml
)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)
set(CMAKE_WARN_DEVELOPER ON)

# Find specific OpenCASCADE components, avoid DataExchange module
find_package(OpenCASCADE REQUIRED COMPONENTS 
    FoundationClasses
    ModelingData
    ModelingAlgorithms
    Visualization
)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Setuav.cpp
)

qt_add_executable(${PROJECT_NAME}App
    ${SOURCES}
    qml.qrc
)

target_include_directories(${PROJECT_NAME}App
    PRIVATE
        ${SRC_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        ${OpenCASCADE_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}App 
    PRIVATE
        Qt6::Quick
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        # Link specific OpenCASCADE libraries instead of all libraries
        TKernel
        TKMath
        TKBRep
        TKGeomBase
        TKGeomAlgo
        TKG3d
        TKG2d
        TKTopAlgo
        TKHLR
        TKMesh
        TKService
        TKV3d
)