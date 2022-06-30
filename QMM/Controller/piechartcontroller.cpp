#include "piechartcontroller.h"


PieChartController::PieChartController(PieChartView *v, Model *m, Controller *c) : Controller(v , m , c){

}

PieChartView *PieChartController::getView() const
{
    return static_cast<PieChartView*>(view);
}

PieChartModel *PieChartController::getModel() const
{
    return static_cast<PieChartModel*>(model);
}

void PieChartController::onCloseView() const
{
    delete this;
}


