#include "homecontroller.h"

homecontroller::homecontroller(QObject *parent)
    : QObject{parent}, homeview(new HomeView()), model(new MainModel())
{
    homeview->show();


    connect(homeview, &HomeView::importButtonClicked, this, &homecontroller::checkTransactionList) ;
    connect(this, &homecontroller::checkedTransactionList, homeview, &HomeView::displayTransaction);
}

void homecontroller::checkTransactionList()
{
    std::vector<Transaction> toBeAdded = JSONImport::getTransactionList(JSONImport::getJSONObject());
    model->updateTransactionList(toBeAdded);
    emit checkedTransactionList(model->getTransactionList());
}
