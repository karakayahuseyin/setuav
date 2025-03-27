// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

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