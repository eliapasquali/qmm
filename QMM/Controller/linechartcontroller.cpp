#include "linechartcontroller.h"

void LineChartController::connectView() const {}

LineChartController::LineChartController(LineChartView* v, Model* m, Controller* parent) :
    Controller(v, new LineChartModel(m), parent)
{

    // Prendi transazioni dal modello
    auto monthlyTotals = getModel()->getMonthlyTotal();
    // Inserisci punti nella view

    getView()->insertPoint(1,0);

    if(!monthlyTotals.empty()) {
        for (auto month : monthlyTotals) {
            getView()->insertPoint(month.first, month.second);
        }
    }

    // Riempie il grafico
    getView()->insertSeries();
    getView()->defineAxis(!monthlyTotals.empty() ? monthlyTotals.rbegin()->first : 12);
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