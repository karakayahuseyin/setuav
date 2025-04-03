#ifndef _Geometry_Header
#define _Geometry_Header

#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>

class Geometry
{
public:
    Geometry( Handle(AIS_InteractiveContext) theContext, Handle(V3d_View) theView);
    ~Geometry();

    void addCube(double x, double y, double z, double size);
    void deleteCube();
    void demoScene();

private:
    Handle(AIS_InteractiveContext) mContext;
    Handle(V3d_View) mView;
};

#endif // _Geometry_Header