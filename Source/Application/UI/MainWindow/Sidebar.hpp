#ifndef _Sidebar_Header
#define _Sidebar_Header

#include "../../Geometry/Editor.hpp"
#include "AirframeMenu.hpp"
#include "PropulsionMenu.hpp"
#include "PerformanceMenu.hpp"

#include <memory>

namespace UI {

class Sidebar {
public:
    Sidebar(Geometry::Editor *geometryEditor);
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

    void renderPageSelector();
    void renderPageMenu();

    std::unique_ptr<AirframeMenu> mAirframeMenu;
    std::unique_ptr<PropulsionMenu> mPropulsionMenu;
    std::unique_ptr<PerformanceMenu> mPerformanceMenu;
};

} // namespace UI

#endif // _Sidebar_Header