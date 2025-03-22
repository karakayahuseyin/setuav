#include "Setuav.h"

int main(int argc, char **argv)
{
    Setuav app(argc, argv);
    app.init();
    return app.exec();
}