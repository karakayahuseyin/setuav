#ifndef _Sidebar_Header
#define _Sidebar_Header

#include "../../Geometry/Editor.hpp"
#include "AirframeMenu.hpp"
#include "PropulsionMenu.hpp"
#include "PerformanceMenu.hpp"

#include <memory>

class Sidebar {
public:
    Sidebar(Editor *geometryEditor);
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
    Editor *mGeometryEditor;

    void renderPageSelector();
    void renderPageMenu();

    std::unique_ptr<AirframeMenu> mAirframeMenu;
    std::unique_ptr<PropulsionMenu> mPropulsionMenu;
    std::unique_ptr<PerformanceMenu> mPerformanceMenu;
};

#endif // _Sidebar_Header