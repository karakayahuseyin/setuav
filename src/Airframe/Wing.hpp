/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

#pragma once

#ifndef WING_H
#define WING_H

#include "Airfoil.hpp"

#include <vector>
    
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

    void addSection(WingSection section);
    void removeSection(int index);
    void editSection(int index);

    std::vector<WingSection> sections() const { return m_sections; }
    int span() const { return m_span; }
    int area() const { return m_area; }

private:
    std::vector<WingSection> m_sections;
    int sectionCount;
    int m_span; // mm
    int m_area; // dm^2
};

#endif // WING_H