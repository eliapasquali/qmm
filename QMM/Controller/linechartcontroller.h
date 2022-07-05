#ifndef LINECHARTCONTROLLER_H
#define LINECHARTCONTROLLER_H

#include "controller.h"
#include "transaction.h"
#include "View/linechartview.h"
#include "Model/linechartmodel.h"

class LineChartController : public Controller
{
    Q_OBJECT

private:
    void connectView() const override;

public:
    explicit LineChartController(LineChartView* v,
                                 Model* m,
                                 Controller* parent = nullptr);

    LineChartView* getView() const override;
    LineChartModel* getModel() const override;


public slots:
    void onCloseView() const override;
};

#endif // LINECHARTCONTROLLER_H
