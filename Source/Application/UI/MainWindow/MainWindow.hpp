#ifndef _MainWindow_Header
#define _MainWindow_Header

#include "../../Window.hpp"
#include "Sidebar.hpp"
#include "Topbar.hpp"

#include <GLFW/glfw3.h>

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace UI {

class MainWindow {
public:
    //! Constructor.
    MainWindow(GLFWwindow* window, Geometry::Editor* geometryEditor);
    ~MainWindow();

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
    // Other MainWindow components can be added here
};

} // namespace UI

#endif // _MainWindow_Header