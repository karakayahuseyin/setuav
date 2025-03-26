/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

#pragma once

#ifndef FIXEDWING_H
#define FIXEDWING_H

#include "Airframe.hpp"

enum class FWType {
    Trainer,
    Sport,
    Aerobatic,
    Scale,
    Glider,
    Custom
};

class FixedWing : public Airframe {
public:
    FixedWing();
    ~FixedWing();

    FWType type() const { return m_type; }

private:
    FWType m_type;
    // Wing m_wing;
    // Tail m_tail;
    // Fuselage m_fuselage;
    // Motor m_motor;
    // Propeller m_propeller;
    // LandingGear m_landingGear;
};

#endif // FIXEDWING_H