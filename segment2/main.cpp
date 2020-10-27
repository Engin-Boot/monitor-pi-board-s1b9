#include <QGuiApplication>
#include "packagereader.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    packageReader pckreader;
    if(!pckreader.initialize())
        return -1;

    return app.exec();
}
