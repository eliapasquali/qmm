#include "piechartcontroller.h"


void PieChartController::connectView() const {}

PieChartController::PieChartController(PieChartView *v, Model *m, Controller *c)
    : Controller(v , new PieChartModel(m) , c)
{
    getView()->setYear(getModel()->getYearRange());

    auto totalPerCategories = getModel()->getTotalPerCategories(getView()->getYear());

    for(auto cat : totalPerCategories){
        getView()->addCategories(cat.first, cat.second);
    }

    getView()->insertSeries();
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


