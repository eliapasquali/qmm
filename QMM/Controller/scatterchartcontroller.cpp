#include "scatterchartcontroller.h"

void ScatterChartController::connectView() const {}

ScatterChartController::ScatterChartController(ScatterChartView* v, Model* m, Controller* parent) :
    Controller(v, new ScatterChartModel(m), parent)
{
    auto transaction = getModel()->getList();
    auto categories = getModel()->getCategories();

    getView()->defineSeries(categories);

    for(auto t : transaction) {
        getView()->insertInSerie(t.getCategory(), t.getDate(), t.getValue());
    }


    getView()->insertSeries();
    getView()->defineAxis(getModel()->getTimeRange(), getModel()->getValueRange());

    connectView();
}

ScatterChartView* ScatterChartController::getView() const
{
    return static_cast<ScatterChartView*>(view);
}

ScatterChartModel* ScatterChartController::getModel() const
{
    return static_cast<ScatterChartModel*>(model);
}

void ScatterChartController::onCloseView() const
{
    delete this;
}
