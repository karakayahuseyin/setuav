/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

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