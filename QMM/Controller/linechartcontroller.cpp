#include "linechartcontroller.h"

void LineChartController::connectView() const {}

LineChartController::LineChartController(LineChartView* v, Model* m, Controller* parent) :
    Controller(v, new LineChartModel(m), parent)
{

    // Prendi transazioni dal modello
    auto monthlyTotals = getModel()->getMonthlyTotals();
    int lastMonth = 12; double min = 0; double max = 0;
    // Inserisci punti nella view

    if(!monthlyTotals.empty()) {
        for (auto month : monthlyTotals) {
            getView()->insertPoint(month.first, month.second);
        }
        lastMonth = monthlyTotals.rbegin()->first;
        auto range = getModel()->getRange();
        min = range.first; max = range.second;
    }

    // Riempie il grafico
    getView()->insertSeries();
    // Crea assi
    getView()->defineAxis(lastMonth, min, max);
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
