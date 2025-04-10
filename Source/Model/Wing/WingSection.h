#ifndef WINGSECTION_H
#define WINGSECTION_H

enum Airfoil
{
    NACA4,
    NACA5
    // Add other airfoil types here
    // Example:
    // Eppler,
    // ...
};

class WingSection
{
public:
    WingSection();
    ~WingSection();

private:
    Airfoil airfoil;        // Pointer to the airfoil object
    float rootChord;        // Root chord length
    float tipChord;         // Tip chord length 
    float span;             // Span length
    float sweepAngle;       // Sweep angle
    float dihedralAngle;    // Dihedral angle
};

#endif // WINGSECTION_H