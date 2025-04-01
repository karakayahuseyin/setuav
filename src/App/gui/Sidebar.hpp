#ifndef _Sidebar_Header
#define _Sidebar_Header

#include <GLFW/glfw3.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Sidebar {
public:
    Sidebar() {}
    ~Sidebar() {}

    void render();

    enum class Page {
        Airframe,
        Propulsion,
        Performance
    };

    Page getCurrentPage() const { return mCurrentPage; }

private:
    Page mCurrentPage = Page::Airframe;
};

#endif // _Sidebar_Header