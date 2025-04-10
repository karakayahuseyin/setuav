// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#pragma once

#ifndef _Naca4_Header
#define _Naca4_Header

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