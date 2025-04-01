# Setuav

**SETUAV** is a tool for UAV design, performance analysis and simulation integrations. Built with **OpenCASCADE** and **ImGui**.

## Dependencies

- OpenCASCADE (installed at C:/Dev/Libraries/OpenCASCADE/)
- GLFW3 (installed via vcpkg)
- Dear ImGui (included in lib/imgui)

Please ensure that library paths are properly configured in CMake.

## Building the Project

### Windows

You can build the project using the provided batch file:

```bat
# For Debug build
build.bat --debug

# For Release build
build.bat --release

# Default (Debug)
build.bat
```

### Manual Build

1. Create a build directory:
   ```
   mkdir build && cd build
   ```

2. Configure with CMake:
   ```
   cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug ..
   ```

3. Build the project:
   ```
   cmake --build . --config Debug
   ```

## Project Structure

- `src/` - Application source code
- `lib/` - Third-party libraries
- `build/` - Build output directory

## License

MIT License

Copyright (c) 2025 Hüseyin Karakaya

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
