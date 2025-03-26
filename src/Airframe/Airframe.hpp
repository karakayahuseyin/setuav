/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

#pragma once

#ifndef AIRFRAME_H
#define AIRFRAME_H

#include <QObject>

/**
 * The Airframe class is a base class for all airframe types.
 * Airframe class is responsible for the physical structure of the UAV.
 * Airframe can be a fixed-wing, rotary-wing, or hybrid.
 * The Airframe class is an abstract class.
 * FixedWing, RotaryWing, and Hybrid classes are derived from the Airframe class.
 */
class Airframe {
public:
    Airframe();
    ~Airframe();

    float weight() const { return m_weight; }
    
private:
    float m_weight; // kg
};

#endif // AIRFRAME_H