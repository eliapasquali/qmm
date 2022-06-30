#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "controller.h"
#include "linechartcontroller.h"
#include "piechartcontroller.h"
#include "Model/homemodel.h"
#include "Model/linechartmodel.h"
#include "View/homeview.h"
#include "View/linechartview.h"
#include "View/piechartview.h"
#include "json_import.h"

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
    void createLineChart();
    void createPieChart();
    void onCloseView() const override;

signals:
    void checkedTransactionList(std::vector<Transaction> p);

};

#endif // HOMECONTROLLER_H
