#include "homecontroller.h"

HomeController::HomeController(HomeView* v, HomeModel* m, Controller* parent) :
    Controller(v, m, parent)
{
    connectToView();
}

HomeView* HomeController::getView() const {
    return static_cast<HomeView*>(view);
}

HomeModel* HomeController::getModel() const {
    return static_cast<HomeModel*>(model);
}

void HomeController::connectToView() const {
    connect(this->getView(), &HomeView::importButtonClicked,
            this, &HomeController::checkTransactionList);
    connect(this, &HomeController::checkedTransactionList,
            this->getView(), &HomeView::displayTransaction);
}

void HomeController::checkTransactionList()
{
    auto m = getModel();
    auto toBeAdded = JSONImport::getTransactionList(JSONImport::getJSONObject());
    m->updateTransactionList(toBeAdded);
    emit checkedTransactionList(m->getTransactionList());
}

void HomeController::onCloseView() const
{
    delete this;
}
