#include "Controller/homecontroller.h"
#include "View/homeview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto* homeView = new HomeView();
    auto* homeController = new HomeController(homeView);
	homeView->show();
	
    return QApplication::exec();
}
