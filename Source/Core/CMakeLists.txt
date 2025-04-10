# Core Library CMakeLists.txt

set(CORE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CORE_SOURCES
    
)

# Create Core library
add_library(Core STATIC ${CORE_SOURCES})

# Include directories
target_include_directories(Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

