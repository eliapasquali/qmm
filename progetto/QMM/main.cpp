#include "homecontroller.h"
#include "homeview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    homecontroller mainctrl;

    return QApplication::exec();
}
