#ifndef _Geom_Editor_Header
#define _Geom_Editor_Header

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>

class Geom_Editor
{
public:
    Geom_Editor(Handle(AIS_InteractiveContext) theContext, Handle(V3d_View) theView);
    ~Geom_Editor();

    // Test methods
    void addCube(double x, double y, double z, double size);
    void deleteCube();
    void demoScene();

    void addObject(Handle(AIS_InteractiveObject) theObject);
    void removeObject(Handle(AIS_InteractiveObject) theObject);

private:
    Handle(AIS_InteractiveContext) mContext;
    Handle(V3d_View) mView;
};

#endif // _Geom_Editor_Header