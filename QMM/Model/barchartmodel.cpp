#include "barchartmodel.h"

BarChartModel::BarChartModel(Model* baseModel)
{
    transactionList = baseModel->getList();
    calculateCategories();
}

void BarChartModel::calculateCategories() {
    for(auto t : transactionList) {
        if(categories.find(t.getCategory())==categories.end())
            categories.insert({t.getCategory(), true});
    }
}

std::vector<Category> BarChartModel::getCategories() const {
    std::vector<Category> names;
    for(auto c : categories) names.push_back(c.first);
    return names;
}

std::map<int, double> BarChartModel::calculateMonthlyTotals(const Category cat, const int year) const
{
    std::map<int, double> monthlyTotals;

    for(int i=1; i<=12; i++) monthlyTotals.insert({i, 0});

    for(auto t : transactionList) {
        auto transactionCat = t.getCategory();
        auto transactionYear = t.getDate().year();

        if(transactionCat==cat && transactionYear==year && t.isOutcome()) {
            auto transactionMonth = t.getDate().month();
            auto transactionValue = t.getValue();

            auto monthlyTotal = monthlyTotals.find(transactionMonth);
            monthlyTotal->second += transactionValue;
        }
    }

    return monthlyTotals;
}
