#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "controller.h"
#include "linechartcontroller.h"
#include "barchartcontroller.h"
#include "scatterchartcontroller.h"
#include "piechartcontroller.h"
#include "areachartcontroller.h"
#include "Model/homemodel.h"
#include "Model/linechartmodel.h"
#include "Model/barchartmodel.h"
#include "Model/scatterchartmodel.h"
#include "Model/piechartmodel.h"
#include "Model/areachartmodel.h"
#include "View/homeview.h"
#include "View/linechartview.h"
#include "View/barchartview.h"
#include "View/scatterchartview.h"
#include "View/piechartview.h"
#include "View/areachartview.h"
#include "json_import.h"
#include "json_export.h"

class HomeController : public Controller
{
    Q_OBJECT

private:
    void connectView() const override;

public:
    HomeController(HomeView* v, HomeModel* m = new HomeModel(), Controller* parent = nullptr);
    HomeView* getView() const override;
    HomeModel* getModel() const override;

public slots:
    void checkTransactionList();
    void exportTransaction();
    void createLineChart();
    void createBarChart();
    void createScatterChart();
    void createPieChart();
    void createAreaChart();
    void insertTransaction(Transaction t);
    void onCloseView() const override;

signals:
    void checkedTransactionList(std::vector<Transaction> p);

};

#endif // HOMECONTROLLER_H
