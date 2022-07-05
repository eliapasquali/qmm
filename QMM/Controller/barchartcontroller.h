#ifndef BARCHARTCONTROLLER_H
#define BARCHARTCONTROLLER_H

#include "controller.h"
#include "View/barchartview.h"
#include "Model/barchartmodel.h"


class BarChartController : public Controller
{
        Q_OBJECT

private:
    void connectView() const override;

public:
    explicit BarChartController(BarChartView* v,
                                Model* m,
                                Controller* parent = nullptr);

    BarChartView* getView() const override;
    BarChartModel* getModel() const override;

public slots:
    void onCloseView() const override;
};

#endif // BARCHARTCONTROLLER_H
