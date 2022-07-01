#ifndef SCATTERCHARTCONTROLLER_H
#define SCATTERCHARTCONTROLLER_H

#include "controller.h"
#include "View/scatterchartview.h"
#include "Model/scatterchartmodel.h"

class ScatterChartController : public Controller
{
    Q_OBJECT

private:
    void connectView() const override;
public:
    explicit ScatterChartController(ScatterChartView* v,
                                    Model* m,
                                    Controller* parent = nullptr);

    ScatterChartView* getView() const override;
    ScatterChartModel* getModel() const override;

public slots:
    void onCloseView() const override;
};

#endif // SCATTERCHARTCONTROLLER_H
