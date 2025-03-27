// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#include "Setuav.hpp"

Setuav::Setuav(int &argc, char **argv) :
    QGuiApplication(argc, argv),
    m_engine(new QQmlApplicationEngine)
{
    setApplicationName(APP_NAME);
}

Setuav::~Setuav()
{
    delete m_engine;
}

void Setuav::init()
{
    const QUrl mainQmlUrl(QStringLiteral("qrc:/qml/Main.qml"));
    QObject::connect(
        m_engine, &QQmlApplicationEngine::objectCreated,
        this, [mainQmlUrl](QObject *obj, const QUrl &objUrl) {
            if (!obj && mainQmlUrl == objUrl) {
                qCritical() << "Failed to load QML file.";
                QCoreApplication::exit(-1);
            }
        },
        Qt::QueuedConnection);

    m_engine->load(mainQmlUrl);
}

void Setuav::shutdown()
{
    m_engine->quit();
}