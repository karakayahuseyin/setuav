#include "Geom_Editor.hpp"

#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <Aspect_Handle.hxx>
#include <Aspect_DisplayConnection.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <TopAbs_ShapeEnum.hxx>

#include <iostream>

Geom_Editor::Geom_Editor(Handle(AIS_InteractiveContext) theContext, Handle(V3d_View) theView)
    : mContext(theContext), mView(theView)
{
    if (mContext.IsNull() || mView.IsNull())
    {
        std::cerr << "Error: Context or View is null." << std::endl;
        return;
    }
}

void Geom_Editor::demoScene()
{
    if (mContext.IsNull())
    {
        return;
    }

    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(0.0, 0.0, 0.0));
    Handle(AIS_Shape) aBox = new AIS_Shape(BRepPrimAPI_MakeBox(anAxis, 50, 50, 50).Shape());
    mContext->Display(aBox, AIS_Shaded, 0, false);
    anAxis.SetLocation(gp_Pnt(25.0, 125.0, 0.0));
    Handle(AIS_Shape) aCone = new AIS_Shape(BRepPrimAPI_MakeCone(anAxis, 25, 0, 50).Shape());
    mContext->Display(aCone, AIS_Shaded, 0, false);

    TCollection_AsciiString aGlInfo;
    {
        TColStd_IndexedDataMapOfStringString aRendInfo;
        mView->DiagnosticInformation(aRendInfo, Graphic3d_DiagnosticInfo_Basic);
        for (TColStd_IndexedDataMapOfStringString::Iterator aValueIter(aRendInfo); aValueIter.More(); aValueIter.Next())
        {
            if (!aGlInfo.IsEmpty()) { aGlInfo += "\n"; }
            aGlInfo += TCollection_AsciiString("  ") + aValueIter.Key() + ": " + aValueIter.Value();
        }
    }
    Message::DefaultMessenger()->Send(TCollection_AsciiString("OpenGL info:\n") + aGlInfo, Message_Info);
}

void Geom_Editor::addCube(double x, double y, double z, double size)
{
    if (mContext.IsNull())
    {
        return;
    }

    if (size <= 0.0)
    {
        Message::DefaultMessenger()->Send(TCollection_AsciiString("Invalid size for cube."), Message_Info);
        return;
    }

    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(x, y, z));
    Handle(AIS_Shape) aBox = new AIS_Shape(BRepPrimAPI_MakeBox(anAxis, size, size, size).Shape());
    mContext->SetColor(aBox, Quantity_NOC_GRAY75, Standard_False);
    mContext->Display(aBox, AIS_Shaded, 0, true);
}

void Geom_Editor::deleteCube()
{
    if (mContext.IsNull())
    {
        return;
    }

    mContext->InitSelected();

    if (mContext->HasSelectedShape())
    {
        mContext->EraseSelected(true);
        return;
    }

    Message::DefaultMessenger()->Send(TCollection_AsciiString("No shape selected to delete."), Message_Info);
}