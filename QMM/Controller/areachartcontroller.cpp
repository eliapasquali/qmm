#include "areachartcontroller.h"

void AreaChartController::connectView() const {}

AreaChartController::AreaChartController(AreaChartView* v, Model* m, Controller* parent)
    : Controller(v, new AreaChartModel(m), parent)
{
    // Ritorna dati dal model
    auto categories = getModel()->getCategories();
    auto selected = getView()->selectCategory(categories);

    getView()->setYear(getModel()->getYearRange());
    getModel()->calculateCategoryTotals(selected, getView()->getYear());

    auto totals = getModel()->getCategoryTotals();
    auto max = getModel()->getMax();

    getView()->defineSeries();
    for(auto t : totals) getView()->insertInSerie(t.first, t.second);
    getView()->insertSerie(selected);
    getView()->defineAxis(max);
}

AreaChartView* AreaChartController::getView() const
{
    return static_cast<AreaChartView*>(view);
}

AreaChartModel* AreaChartController::getModel() const
{
    return static_cast<AreaChartModel*>(model);
}

void AreaChartController::onCloseView() const
{
    delete this;
}

