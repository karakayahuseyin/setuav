/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

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