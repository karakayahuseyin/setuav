// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#include "Airframe.hpp"

#include <QDebug>

Airframe::Airframe()
{
    qDebug() << "Airframe created.";
}

Airframe::~Airframe()
{
    qDebug() << "Airframe destroyed.";
}