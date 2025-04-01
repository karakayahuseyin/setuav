#ifndef _Setuav_Header
#define _Setuav_Header

#include "Window.hpp"
#include "OcctView.hpp"
#include "gui/Gui.hpp"

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
    void initOcctView();

    //! Init ImGui.
    void initGui();

    //! Render ImGUI.
    void renderGui();

    //! Application event loop.
    void mainloop();

    //! Clean up before .
    void cleanup();

public:

    Window* getWindow () { return mWindow.get(); }
    OcctView* getOcctView () { return mOcctView; }
    Gui* getGui () { return mGui; }

private:

    Handle(Window) mWindow;
    OcctView* mOcctView;
    Gui* mGui;

    // Handle(AirframeView) mAirframeView;
    // Handle(PropulsionView) mPropulsionView;
    // Handle(PerformanceView) mPerformanceView;
};

#endif // _Setuav_Header