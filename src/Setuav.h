#pragma once

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
