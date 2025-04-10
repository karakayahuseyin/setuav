#ifndef BATTERY_H
#define BATTERY_H

#include "BatteryCell.h"

/**
 * @class Battery
 * @brief Base class for all battery types.
 */
class Battery 
{
public:
    Battery();
    ~Battery();

private:
    BatteryCell cell; // Battery cell type
    float oarallel_cells; // Number of parallel cells
    float series_cells; // Number of series cells
};

#endif // BATTERY_H
