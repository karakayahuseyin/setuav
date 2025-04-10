// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#pragma once

#ifndef _Airframe_Header
#define _Airframe_Header

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

#endif // _Airframe_Header