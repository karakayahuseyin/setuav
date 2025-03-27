// Copyright (C) 2025 Hüseyin Karakaya
// This file is part of Setuav, licensed under GNU GPL v3.

#include "Setuav.hpp"
#include "Airframe/Airframe.hpp"

int main(int argc, char **argv)
{
    /* Test */
#ifdef AIRFRAME_H
    Airframe airframe;
#endif
    Setuav app(argc, argv);
    app.init();
    return app.exec();
}