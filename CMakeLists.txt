cmake_minimum_required(VERSION 3.10)

project(setuav VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core Gui Qml)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)
set(CMAKE_WARN_DEVELOPER ON)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

qt_add_executable(${PROJECT_NAME}App
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Setuav.cpp
    qml.qrc
)

target_link_libraries(${PROJECT_NAME}App 
    PRIVATE
        Qt6::Quick
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)

target_include_directories(${PROJECT_NAME}App
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)