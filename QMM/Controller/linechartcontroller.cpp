#include "linechartcontroller.h"

void LineChartController::connectView() const {}

LineChartController::LineChartController(LineChartView* v, LineChartModel* m, Controller* parent) :
    Controller(v, m, parent)
{
    connectView();
}

LineChartView* LineChartController::getView() const
{
    return static_cast<LineChartView*>(view);
}

LineChartModel* LineChartController::getModel() const
{
    return static_cast<LineChartModel*>(model);
}

void LineChartController::onCloseView() const
{
    delete this;
}
