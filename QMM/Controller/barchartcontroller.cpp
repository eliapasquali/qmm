#include "barchartcontroller.h"

void BarChartController::connectView() const {}

BarChartController::BarChartController(BarChartView* v, Model* m, Controller* parent) :
    Controller(v, new BarChartModel(m), parent)
{
    // Ritorna dati dal model
    auto categories = getModel()->getCategories();

    getView()->defineSets(categories);

    for(auto cat : categories) {
        auto monthlyTotals = getModel()->calculateMonthlyTotals(cat, getView()->getYear());
        for(auto m : monthlyTotals) getView()->insertInSet(cat, m.second*-1);
    }

    getView()->insertSeries();
    getView()->defineAxis();
}

BarChartView* BarChartController::getView() const
{
    return static_cast<BarChartView*>(view);
}

BarChartModel* BarChartController::getModel() const
{
    return static_cast<BarChartModel*>(model);
}

void BarChartController::onCloseView() const
{
    delete this;
}
