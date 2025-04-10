#ifndef WING_H
#define WING_H

#include "WingSection.h"

#include <vector>

class Wing
{
public:
    Wing();
    ~Wing();

private:
    std::vector<WingSection> sections;  // Vector of wing sections
    int numSections;                    // Number of sections in the wing
    float span;                         // Span length
    float aspectRatio;                  // Aspect ratio of the wing
};

#endif // WING_H