#ifndef _Topbar_Header
#define _Topbar_Header

#include <GLFW/glfw3.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

class Topbar {
public:
    Topbar() {}
    ~Topbar() {}

    void render();
};

#endif // _Topbar_Header