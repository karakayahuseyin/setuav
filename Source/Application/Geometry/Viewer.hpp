#ifndef _Viewer_Header
#define _Viewer_Header

#include "../ApplicationWindow.hpp"

#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>
#include <V3d_View.hxx>

//! Sample class creating 3D Viewer within GLFW window.
class Viewer : protected AIS_ViewController
{
public:
    Viewer(const Handle(ApplicationWindow)& theWindow);
    ~Viewer();

    void init();
    void render();
    void cleanup();

    Handle(AIS_InteractiveContext) getContext() const { return mContext; }
    Handle(V3d_View) getView() const { return mView; }

public:
    //! Handle view redraw.
    void handleViewRedraw(const Handle(AIS_InteractiveContext)& theCtx,
        const Handle(V3d_View)& theView) override;

    //! @name GLWF callbacks
    //! Window resize event.
    void onResize(int theWidth, int theHeight);

    //! Mouse scroll event.
    void onMouseScroll(double theOffsetX, double theOffsetY);

    //! Mouse click event.
    void onMouseButton(int theButton, int theAction, int theMods);

    //! Mouse move event.
    void onMouseMove(int thePosX, int thePosY);

    //! @name GLWF callbacks (static functions)

    //! GLFW callback redirecting messages into Message::DefaultMessenger().
    static void errorCallback(int theError, const char* theDescription);

    //! Wrapper for glfwGetWindowUserPointer() returning this class instance.
    static Viewer* toView(GLFWwindow* theWin);

    //! Window resize callback.
    static void onResizeCallback(GLFWwindow* theWin, int theWidth, int theHeight)
    {
        toView(theWin)->onResize(theWidth, theHeight);
    }

    //! Frame-buffer resize callback.
    static void onFBResizeCallback(GLFWwindow* theWin, int theWidth, int theHeight)
    {
        toView(theWin)->onResize(theWidth, theHeight);
    }

private:

    Handle(ApplicationWindow) mWindow;
    Handle(V3d_View) mView;
    Handle(AIS_InteractiveContext) mContext;
    bool myToWaitEvents = false;
};

#endif // _Viewer_Header