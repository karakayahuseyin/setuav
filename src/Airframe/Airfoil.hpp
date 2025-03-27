// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#pragma once

#ifndef AIRFOIL_H
#define AIRFOIL_H

enum AirfoilType {
    NACA4Digit,
    NACA5Digit,
    NACA6Series,
    Selig,
    Lednicer,
    Eppler,
    Other
};

class Airfoil {
public:
    Airfoil();
    ~Airfoil() = delete;
};

#endif // AIRFOIL_H