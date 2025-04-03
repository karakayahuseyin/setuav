#ifndef _Sidebar_Header
#define _Sidebar_Header

#include "../occt/Geometry.hpp"

#include <GLFW/glfw3.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Sidebar {
public:
    Sidebar(Geometry *geometry) : mGeometry(geometry) {}
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
    Geometry * mGeometry;
};

#endif // _Sidebar_Header