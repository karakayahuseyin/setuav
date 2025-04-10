// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#pragma once

#ifndef _Wing_Header
#define _Wing_Header

#include "Airfoil.hpp"

#include <vector>
#include <memory>

struct WingSection {
    Airfoil airfoil;
    double span;
    double rootChord;
    double tipChord;
    double sweep;
    double dihedral;
    double twist;
};

class Wing {
public:
    Wing();
    ~Wing() = delete;

    void addSection(std::shared_ptr<WingSection> section);
    void createSection(Airfoil airfoil, double span, double rootChord, 
                    double tipChord, double sweep, double dihedral, double twist);
    void removeSection(int index);
    void editSection(int index);

    std::vector<std::shared_ptr<WingSection>> sections() const { return m_sections; }
    int span() const { return m_span; }
    int area() const { return m_area; }

private:
    std::vector<std::shared_ptr<WingSection>> m_sections;
    int sectionCount;
    int m_span; // mm
    int m_area; // dm^2
};

#endif // WING_H