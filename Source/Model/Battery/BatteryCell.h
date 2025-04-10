#ifndef BATTERYCELL_H
#define BATTERYCELL_H

class BatteryCell
{
public:
    BatteryCell();
    ~BatteryCell();

private:
    float voltage; // in volts
    float capacity; // in mAh
    float internalResistance; // in ohms
    float dischargeRate; // in C (capacity per hour)
    float chargeRate; // in C (capacity per hour)
};

#endif // BATTERYCELL_H