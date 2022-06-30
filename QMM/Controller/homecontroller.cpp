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
    connect(view, &HomeView::pieChartClicked,
            this, &HomeController::createPieChart);
}

void HomeController::checkTransactionList()
{
    auto m = getModel();
    auto toBeAdded = JSONImport::getTransactionList(JSONImport::getJSONObject());
    m->updateList(toBeAdded);
    emit checkedTransactionList(m->getList());
}

void HomeController::createLineChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto lineChartView = new LineChartView();
    lineChartView->setTitle("Andamento periodico");
    auto lineChartController = new LineChartController(lineChartView, m, this);
    lineChartController->getModel()->setList(transactions);
    lineChartController->makeVisibile();
}

void HomeController::createPieChart()
{
    auto m = getModel();
    auto p = new PieChartView();
    p->setTitle("Spese per tipologia");
    auto pieChartController = new PieChartController(p, m, this);
    pieChartController->makeVisibile();
}


void HomeController::onCloseView() const
{
    delete this;
}
