#include "linechartmodel.h"

LineChartModel::LineChartModel(Model* baseModel) {
    transactionList = baseModel->getList();
    calculateMonthlyTotals();
}

void LineChartModel::calculateMonthlyTotals()
{
    for(auto t : transactionList) {
        auto month = t.getDate().month();
        auto value = t.getValue();
        if(totals.find(month)!=totals.end()) value += totals.find(month)->second;
        totals.insert({month, value});
    }

    auto firstMonth = totals.begin()->first;
    for(int i=1; i<firstMonth; i++) totals.insert({i, 0});

}

std::map<int, double> LineChartModel::getMonthlyTotals() const{
    return totals;
}

std::pair<double, double> LineChartModel::getRange() const {
    auto min = std::numeric_limits<double>::max();
    auto max = std::numeric_limits<double>::min();

    for(auto t : totals) {
        if(t.second < min) min = t.second;
        if(t.second > max) max = t.second;
    }

    // Arrotonda alla migliaia poi +1000
    min = ((std::floor(min/ 1000))-1) * 1000;
    max = ((std::ceil(max/ 1000))+1) * 1000;
    auto range = std::pair<double, double>{min, max};
    return range;
}
