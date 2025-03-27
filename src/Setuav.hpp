// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#pragma once

#ifndef SETUAV_H
#define SETUAV_H

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#define APP_NAME "Setuav"

class Setuav : public QGuiApplication
{
    Q_OBJECT

public:
    Setuav(int &argc, char **argv);
    ~Setuav();

    void init();
    void shutdown();

    QQmlApplicationEngine *engine() const {return m_engine;}

private:
    QQmlApplicationEngine *m_engine;
};

#endif // SETUAV_H