#ifndef _Editor_Header
#define _Editor_Header

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>

namespace Geometry {

class Editor
{
public:
    Editor( Handle(AIS_InteractiveContext) theContext, Handle(V3d_View) theView);
    ~Editor();

    // Test methods
    void addCube(double x, double y, double z, double size);
    void deleteCube();
    void demoScene();

private:
    Handle(AIS_InteractiveContext) mContext;
    Handle(V3d_View) mView;
};

} // namespace Geometry

#endif // _Editor_Header