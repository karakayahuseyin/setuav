#ifndef AIRFRAME_H
#define AIRFRAME_H

/**
 * @class Airframe
 * @brief Base class for all airframe types.
 */
class Airframe 
{
public:
    Airframe();
    virtual ~Airframe();

private:
    float weight;
};

#endif // AIRFRAME_H