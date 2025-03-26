/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

#pragma once

#ifndef NACA4_H
#define NACA4_H

#include "Airfoil.hpp"

#include <string>

class Naca4 : public Airfoil {
public:
    Naca4(std::string name);
    Naca4(std::string name, int thickness, int camber, int maxCamberPos);
    ~Naca4() = delete;

private:
    std::string m_name;
    int m_maxCamber;
    int m_maxCamberPos;
    int m_thickness;
};

#endif // NACA4_H