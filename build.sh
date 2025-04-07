#!/bin/bash

# Set default build variables
BUILD_DIR=build
CONFIG=Release

# Parse command-line arguments
if [ "$1" == "--debug" ]; then
    CONFIG=Debug
    echo "Building in Debug mode..."
elif [ "$1" == "--release" ]; then
    CONFIG=Release
    echo "Building in Release mode..."
elif [ -z "$1" ]; then
    echo "No build mode specified. Using default: $CONFIG"
else
    echo "Unknown argument: $1"
    echo "Usage: $0 [--debug|--release]"
    echo "Defaulting to: $CONFIG"
fi

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir -p "$BUILD_DIR"
fi

# Navigate to build directory
cd "$BUILD_DIR"

# Run CMake to configure the project
cmake -DCMAKE_BUILD_TYPE="$CONFIG" ..

# Build the project using all available cores
cmake --build . -- -j$(nproc)

# Return to the original directory
cd ..

echo "Build process completed for $CONFIG configuration."
