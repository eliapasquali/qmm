#include "Controller/homecontroller.h"
#include "View/homeview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("Resources/icon.ico"));

    auto* homeView = new HomeView();
    auto* homeController = new HomeController(homeView);
    homeController->makeVisibile();

    return a.exec();
}
