#ifndef _Gui_Header
#define _Gui_Header

#include "Window.hpp"
#include "Sidebar.hpp"
#include "Topbar.hpp"

#include <GLFW/glfw3.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Gui {
public:
    //! Constructor.
    Gui(GLFWwindow* window);
    ~Gui();

    void init();
    void render();
    void cleanup();

    Sidebar::Page getCurrentPage() const { return mSidebar->getCurrentPage(); }

private:
    // Helper function to begin a new ImGui frame
    void beginFrame();
    // Helper function to end and render the ImGui frame
    void endFrame();

    GLFWwindow* mWindow;
    Topbar* mTopbar;
    Sidebar* mSidebar;
    // Other GUI components can be added here
};

#endif // _Gui_Header