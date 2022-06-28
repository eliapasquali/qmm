#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "controller.h"
#include "Model/homemodel.h"
#include "View/homeview.h"
#include "json_import.h"

class HomeController : public Controller
{
    Q_OBJECT

private:
    void connectToView() const override;

public:
    HomeController(HomeView* v, HomeModel* m = new HomeModel(), Controller* parent = nullptr);
    HomeView* getView() const override;
    HomeModel* getModel() const override;

public slots:
    void checkTransactionList();
    void onCloseView() const override;

signals:
    void checkedTransactionList(std::vector<Transaction> p);

};

#endif // HOMECONTROLLER_H
