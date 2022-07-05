#include "linechartmodel.h"

LineChartModel::LineChartModel(Model* baseModel) {
    transactionList = baseModel->getList();
}

std::map<int, double> LineChartModel::calculateMonthlyTotals(const int year)
{
    for(auto t : transactionList) {
        auto t_month = t.getDate().month();
        auto t_year = t.getDate().year();
        auto t_value = t.getValue();
        if(t_year == year) {
            if(totals.find(t_month)!=totals.end())
                t_value += totals.find(t_month)->second;
            totals.insert({t_month, t_value});
        }
    }

    auto firstMonth = totals.begin()->first;
    for(int i=1; i<firstMonth; i++) totals.insert({i, 0});

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
