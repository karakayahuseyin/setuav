#ifndef _Sidebar_Header
#define _Sidebar_Header

#include "../../Geometry/Editor.hpp"

#include <GLFW/glfw3.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace UI {

class Sidebar {
public:
    Sidebar(Geometry::Editor *geometryEditor) : mGeometryEditor(geometryEditor) {}
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
    Geometry::Editor *mGeometryEditor;
};

} // namespace UI

#endif // _Sidebar_Header