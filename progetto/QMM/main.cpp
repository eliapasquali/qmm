#include "homeview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeView home;
    home.show();
    return a.exec();
}
