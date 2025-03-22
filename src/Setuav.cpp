/**
 * Copyright (C) 2025 Hüseyin Karakaya github.com/karakayahuseyin
 * This file is part of the Setuav project and is licensed under the Apache License 2.0.
 * For more information, see the LICENSE file in the Setuav project root directory.
 */

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