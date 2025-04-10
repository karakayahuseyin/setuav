#ifndef _Setuav_Header
#define _Setuav_Header

#include "ApplicationWindow.hpp"
#include "UI/MainWindow/MainWindow.hpp"
#include "Geometry/Viewer.hpp"
#include "Geometry/Editor.hpp"

class Setuav
{
public:
    Setuav();
    ~Setuav();

    void run();

private:

    //! Create GLFW window.
    void initWindow(int theWidth, int theHeight, const char* theTitle);

    //! Create 3D Viewer.
    void initGeometryViewer();

    //! Init ImGui.
    void initMainWindow();

    //! Application event loop.
    void mainloop();

    //! Clean up before .
    void cleanup();

public:
    ApplicationWindow* getWindow () { return mWindow.get(); }
    Viewer* getGeometryViewer () { return mGeometryViewer; }
    MainWindow* getMainWindow () { return mMainWindow; }

private:

    Handle(ApplicationWindow) mWindow;
    Viewer *mGeometryViewer;
    MainWindow *mMainWindow;
    Editor *mGeometryEditor;

    // Handle(AirframeView) mAirframeView;
    // Handle(PropulsionView) mPropulsionView;
    // Handle(PerformanceView) mPerformanceView;
};

#endif // _Setuav_Header