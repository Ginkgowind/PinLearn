#include "PinWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PinWindow w;
    w.show();

    return a.exec();
}

