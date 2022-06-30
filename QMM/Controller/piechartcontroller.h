#ifndef PIECHARTCONTROLLER_H
#define PIECHARTCONTROLLER_H

#include "controller.h"
#include "View/piechartview.h"
#include "Model/piechartmodel.h"

class PieChartController : public Controller
{

private:
    //void connectView() const override;
public:
    explicit PieChartController(PieChartView* v,Model* m = new PieChartModel(), Controller* c = nullptr);

    PieChartView* getView() const override;
    PieChartModel* getModel() const override;


public slots:
    void onCloseView() const override;
};

#endif // PIECHARTCONTROLLER_H
