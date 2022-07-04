#include "scatterchartmodel.h"

ScatterChartModel::ScatterChartModel(Model* baseModel)
{
    transactionList = baseModel->getList();
    calculateAllAttributes();
}

void ScatterChartModel::calculateAllAttributes() {
    valueRange.first = std::numeric_limits<double>::max();
    valueRange.second = std::numeric_limits<double>::min();
    for(auto t : transactionList) {
        if(categories.find(t.getCategory())==categories.end())
            categories.insert({t.getCategory(), true});
        if(t.getValue() < valueRange.first) valueRange.first = t.getValue();
        if(t.getValue() > valueRange.second) valueRange.second = t.getValue();
    }

    // Arrotonda alla migliaia poi +1000
    valueRange.first = ((std::floor(valueRange.first / 1000))-1) * 1000;
    valueRange.second = ((std::ceil(valueRange.second / 1000))+1) * 1000;
}

std::vector<Category> ScatterChartModel::getCategories() const {
    std::vector<Category> names;
    for(auto c : categories) names.push_back(c.first);
    return names;
}

std::pair<double, double> ScatterChartModel::getValueRange() const
{
    return valueRange;
}
