#include "homecontroller.h"

homecontroller::homecontroller(QObject *parent)
    : QObject{parent}, homeview(new HomeView()), model(new MainModel())
{
    homeview->show();

    connect(homeview, &HomeView::graph1Clicked, this, &homecontroller::calcolaNumero) ;
    connect(this, &homecontroller::calcolatoNumero, homeview, &HomeView::cambiaEtichetta);
}



void homecontroller::calcolaNumero()
{
    int c = model->calcolaSpesa(1,2);
    emit calcolatoNumero(c);
}
