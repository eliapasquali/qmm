#include "areachartmodel.h"

AreaChartModel::AreaChartModel(Model* baseModel)
{
    transactionList = baseModel->getList();
    calculateCategories();
}

void AreaChartModel::calculateCategories() {
    for(auto t : transactionList) {
        if(categories.find(t.getCategory())==categories.end())
            categories.insert({t.getCategory(), true});
    }
}

std::vector<Category> AreaChartModel::getCategories() const {
    std::vector<Category> names;
    for(auto c : categories) names.push_back(c.first);
    return names;
}

void AreaChartModel::calculateCategoryTotals(Category cat)
{
    for(auto t : transactionList) {
        if(t.getCategory() == cat && t.isOutcome()) {
            auto month = t.getDate().month();
            auto value = t.getValue() *-1;
            if(totals.find(month)!=totals.end()) value += totals.find(month)->second;
            totals.insert({month, value});
        }
    }

    for(int m=1; m<=12; m++)
        if(totals.find(m)==totals.end()) totals.insert({m, 0});
}

std::map<int, double> AreaChartModel::getCategoryTotals() const
{
    return totals;
}

double AreaChartModel::getMax() const
{
    double max = std::numeric_limits<double>::min();
    if(!totals.empty()) {
        for(auto t : totals) if(t.second > max) max = t.second;
    } else max=0;

    return max;
}
