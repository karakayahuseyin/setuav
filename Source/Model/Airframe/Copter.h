#ifndef COPTER_H
#define COPTER_H

#include "Airframe.h"

/**
 * @class Copter
 * @brief Base class for all copter types.
 */
class Copter : public Airframe
{
public:
    Copter();
    ~Copter();
};

#endif // COPTER_H