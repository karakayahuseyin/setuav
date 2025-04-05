# Setuav

**SETUAV** is a tool for UAV design, performance analysis and simulation integrations. 

## Dependencies

- OpenCASCADE (install with setup.bat)
- GLFW3 (installed via vcpkg)
- Dear ImGui (included in Source/Lib/imgui as submodule)

Please ensure that library paths are properly configured in CMake.

## Building the Project

### Windows

Setup environment & install libraries:
```bat
setup.bat
```

You can build the project using the provided batch file:

```bat
# For Debug build
build.bat --debug

# For Release build
build.bat --release

# Default (Debug)
build.bat
```

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
