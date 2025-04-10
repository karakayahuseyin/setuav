# Model Library CMakeLists.txt

set(MODEL_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODEL_HEADERS
    Airframe/Airframe.h
    Airframe/Copter.h 
    Airframe/Plane.h
    Battery/Battery.h
    Battery/BatteryCell.h
    Wing/Wing.h
    Wing/WingSection.h
)

# Create Model library
add_library(Model STATIC ${MODEL_SOURCES})

# Include directories
target_include_directories(Model PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Create a namespaced alias
add_library(Setuav::Model ALIAS Model)
