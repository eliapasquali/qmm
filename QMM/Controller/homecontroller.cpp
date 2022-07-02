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
    connect(view, &HomeView::exportButtonClicked,
            this, &HomeController::exportTransaction);
    connect(this, &HomeController::checkedTransactionList,
            view, &HomeView::displayTransaction);
    connect(view, &HomeView::lineChartClicked,
            this, &HomeController::createLineChart);
    connect(view, &HomeView::barChartClicked,
            this, &HomeController::createBarChart);
    connect(view, &HomeView::scatterChartClicked,
            this, &HomeController::createScatterChart);
    connect(view, &HomeView::pieChartClicked,
            this, &HomeController::createPieChart);
    connect(view, &HomeView::createdTransaction,
            this, &HomeController::insertTransaction);
}

void HomeController::checkTransactionList()
{
    auto m = getModel();
    auto toBeAdded = JSONImport::getTransactionList(JSONImport::getJSONObject());
    m->updateList(toBeAdded);
    emit checkedTransactionList(m->getList());
}

void HomeController::insertTransaction(Transaction t)
{
    auto m = getModel();
    m->addTransaction(t);
    emit checkedTransactionList(m->getList());
}

void HomeController::exportTransaction()
{
    std::cout << "ciao";
    auto m = getModel();
    json_export::exportTransaction(m->getList());
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

void HomeController::createBarChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto barChartView = new BarChartView();
    barChartView->setTitle("Uscite mensili per categoria");
    auto barChartController = new BarChartController(barChartView, m, this);
    barChartController->getModel()->setList(transactions);
    barChartController->makeVisibile();
}

void HomeController::createScatterChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto scatterChartView = new ScatterChartView();
    scatterChartView->setTitle("Tutte le transazioni");
    auto scatterChartController = new ScatterChartController(scatterChartView, m, this);
    scatterChartController->getModel()->setList(transactions);
    scatterChartController->makeVisibile();
}

void HomeController::createPieChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto p = new PieChartView();
    p->setTitle("Spese per tipologia");
    auto pieChartController = new PieChartController(p, m, this);
    pieChartController->getModel()->setList(transactions);
    pieChartController->makeVisibile();
}


void HomeController::onCloseView() const
{
    delete this;
}
