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
            this, &HomeController::importTransaction);
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
    connect(view, &HomeView::areaChartClicked,
            this, &HomeController::createAreaChart);
    connect(view, &HomeView::createdTransaction,
            this, &HomeController::insertTransaction);
    connect(view, &HomeView::deleteButtonClicked,
            this, &HomeController::deleteTransaction);
}

void HomeController::importTransaction()
{
    if(getView()->questionMessage("Finestra di importazione", "Ogni transazione già presente nel file verrà sovrascritta, procedere comunque?")){
        auto m = getModel();

        QString path = JSONImport::filePicker();
        QJsonDocument* doc = JSONImport::getJSONDocument(path);

        if(path.isNull()){
            getView()->errorMessage("Inserimento cancellato");
            return;
        }

        if(doc->isNull()){
            getView()->errorMessage("Operazione cancellata");
            return;
        }

        QJsonObject* obj = new QJsonObject(doc->object());
        m->setList(JSONImport::getTransactionList(obj));
        emit checkedTransactionList(m->getList());
    }

}

void HomeController::exportTransaction()
{
    auto m = getModel();
    if(!m->getList().empty())
        json_export::exportTransaction(m->getList());
    else
        getView()->errorMessage("inserire almeno una transazione");
}


void HomeController::insertTransaction(const Transaction& t)
{
    auto m = getModel();
    m->addTransaction(t);
    emit checkedTransactionList(m->getList());
}

void HomeController::deleteTransaction(int indexTransaction)
{
    auto m = getModel();
    m->removeTransaction(indexTransaction);
    emit checkedTransactionList(m->getList());
}

void HomeController::createLineChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto years = m->getYearRange();
    if(!transactions.empty()){
        auto lineChartView = new LineChartView();
        if(lineChartView->setYear(years)) {
            lineChartView->setTitle("Andamento periodico");
            auto lineChartController = new LineChartController(lineChartView, m, this);
            lineChartController->getModel()->setList(transactions);
            lineChartController->makeVisibile();
        } else delete lineChartView;
    }
    else getView()->errorMessage("Dati insufficienti, inserire almeno una transazione");
}

void HomeController::createBarChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto years = m->getYearRange();
    if(!transactions.empty() && !m->isOnlyIncome()){
        auto barChartView = new BarChartView();
        if(barChartView->setYear(years)) {
            barChartView->setTitle("Uscite mensili per categoria");
            auto barChartController = new BarChartController(barChartView, m, this);
            barChartController->getModel()->setList(transactions);
            barChartController->makeVisibile();
        } else delete barChartView;
    }
    else getView()->errorMessage("Dati insufficienti, inserire almeno una spesa");
}

void HomeController::createScatterChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto years = m->getYearRange();
    if(!transactions.empty()){
        auto scatterChartView = new ScatterChartView();
        if(scatterChartView->setYear(years)) {
            scatterChartView->setTitle("Tutte le transazioni");
            auto scatterChartController = new ScatterChartController(scatterChartView, m, this);
            scatterChartController->getModel()->setList(transactions);
            scatterChartController->makeVisibile();
        } else delete scatterChartView;
    }
    else getView()->errorMessage("Dati insufficienti, inserire almeno una transazione");
}

void HomeController::createPieChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto years = m->getYearRange();
    if(!transactions.empty() && !m->isOnlyIncome()){
        auto p = new PieChartView();
        if(p->setYear(years)) {
            p->setTitle("Spese per tipologia");
            auto pieChartController = new PieChartController(p, m, this);
            pieChartController->getModel()->setList(transactions);
            pieChartController->makeVisibile();
        } else delete p;
    }
    else getView()->errorMessage("Dati insufficienti, inserire almeno una spesa");
}

void HomeController::createAreaChart()
{
    auto m = getModel();
    auto transactions = m->getList();
    auto years = m->getYearRange();
    if(!transactions.empty() && !m->isOnlyIncome()) {
        auto v = new AreaChartView();
        if(v->setYear(years)) {
            v->setTitle("Uscite mensili per categoria");
            auto areaChartController = new AreaChartController(v, m, this);
            areaChartController->getModel()->setList(transactions);
            areaChartController->makeVisibile();
        } else delete v;
    }
    else getView()->errorMessage("Dati insufficienti, inserire almeno una spesa");
}

void HomeController::onCloseView() const
{
    delete this;
}
