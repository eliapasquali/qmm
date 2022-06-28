#include "homecontroller.h"

HomeController::HomeController(HomeView* v, HomeModel* m, Controller* parent) :
    Controller(v, m, parent)
{
    connectView();
}

HomeView* HomeController::getView() const {
    return static_cast<HomeView*>(view);
}

HomeModel* HomeController::getModel() const {
    return static_cast<HomeModel*>(model);
}

void HomeController::connectView() const {
    auto view = getView();
    connect(view, &HomeView::importButtonClicked,
            this, &HomeController::checkTransactionList);
    connect(this, &HomeController::checkedTransactionList,
            view, &HomeView::displayTransaction);
    connect(view, &HomeView::lineChartClicked,
            this, &HomeController::createLineChart);
}

void HomeController::checkTransactionList()
{
    auto m = getModel();
    auto toBeAdded = JSONImport::getTransactionList(JSONImport::getJSONObject());
    m->updateTransactionList(toBeAdded);
    emit checkedTransactionList(m->getTransactionList());
}

void HomeController::createLineChart()
{
    auto m = getModel();
    auto transactions = m->getTransactionList();
    auto lineChartView = new LineChartView();
    lineChartView->setTitle("Spesa per categoria");
    auto lineChartController = new LineChartController(lineChartView, new LineChartModel(), this);
    lineChartController->makeVisibile();
}

void HomeController::onCloseView() const
{
    delete this;
}
