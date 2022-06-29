#include "linechartcontroller.h"

void LineChartController::connectView() const {}

LineChartController::LineChartController(LineChartView* v, Model* m, Controller* parent) :
    Controller(v, new LineChartModel(m), parent)
{

    // Prendi transazioni dal modello
    auto monthlyTotals = getModel()->getMonthlyTotal();
    // Inserisci punti nella view

    getView()->insertPoint(0,0);
    for (auto month : monthlyTotals) {
        getView()->insertPoint(month.first, month.second);
    }

    // Riempie il grafico
    getView()->insertSeries();

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
