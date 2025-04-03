#ifndef _OcctView_Header
#define _OcctView_Header

#include "../Window.hpp"

#include <AIS_InteractiveContext.hxx>
#include <AIS_ViewController.hxx>
#include <V3d_View.hxx>

//! Sample class creating 3D Viewer within GLFW window.
class OcctView : protected AIS_ViewController
{
public:
    OcctView(const Handle(Window)& theWindow);
    ~OcctView();

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
    static OcctView* toView(GLFWwindow* theWin);

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

    //! Mouse scroll callback.
    static void onMouseScrollCallback(GLFWwindow* theWin, double theOffsetX, double theOffsetY)
    {
        toView(theWin)->onMouseScroll(theOffsetX, theOffsetY);
    }

    //! Mouse click callback.
    static void onMouseButtonCallback(GLFWwindow* theWin, int theButton, int theAction, int theMods)
    {
        toView(theWin)->onMouseButton(theButton, theAction, theMods);
    }

    //! Mouse move callback.
    static void onMouseMoveCallback(GLFWwindow* theWin, double thePosX, double thePosY)
    {
        toView(theWin)->onMouseMove((int)thePosX, (int)thePosY);
    }

private:

    Handle(Window) mWindow;
    Handle(V3d_View) mView;
    Handle(AIS_InteractiveContext) mContext;
    bool myToWaitEvents = false;
};

#endif // _OcctView_Header