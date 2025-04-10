#ifndef PLANE_H
#define PLANE_H

#include "Airframe.h"

/**
 * @class Plane
 * @brief Base class for all plane types.
 */
class Plane : public Airframe
{
public:
    Plane();
    ~Plane();
};

#endif // PLANE_H
