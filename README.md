# SETUAV
SETUAV is a tool for UAV design, performance analysis and simulation entegrations.

## Build Instructions (Linux)

### Prerequisites
- C++17 compatible compiler (GCC 8+ or Clang)
- CMake (version 3.10 or newer)
- Qt 6.5+ (with Quick, Core, Gui, and Qml components)
- OpenCASCADE (with required components)

### Installing Dependencies (Ubuntu/Debian)
```bash
# Install OpenCASCADE development libraries
# (Package names may vary by distribution)
# For Ubuntu 22.04 Jammy Jelfish:
$ sudo apt install libocct-foundation-dev libocct-modeling-data-dev libocct-modeling-algorithms-dev libocct-visualization-dev
```

### Building SETUAV
```bash
# Clone the repository (if you haven't already)
git clone https://github.com/username/setuav.git
cd setuav

# Create a build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
make -j$(nproc)
```

### Running SETUAV
```bash
# From the build directory
./setuavApp
```

