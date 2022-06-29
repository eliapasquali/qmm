#include "linechartmodel.h"

LineChartModel::LineChartModel(Model* baseModel) {
    transactionList = baseModel->getList();
}

std::map<int, double> LineChartModel::getMonthlyTotal() const{
    std::map<int, double> totals;
    for(auto t : transactionList) {
        auto month = t.getDate().month();
        auto value = t.getValue();
        if(totals.find(month)!=totals.end()) value += totals.find(month)->second;
        totals.insert({month, value});
    }

    return totals;
}
