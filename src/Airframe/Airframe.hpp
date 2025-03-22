/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

#pragma once

#ifndef AIRFRAME_H
#define AIRFRAME_H

#include <QObject>

class Airframe : public QObject
{
    Q_OBJECT
public:
    Airframe();
    ~Airframe();
};

#endif // AIRFRAME_H