#include "model.h"

Model::Model() {}

void Model::setList(const std::vector<Transaction> &tList) {
    transactionList = tList;
}

std::vector<Transaction> Model::getList() const {
    return transactionList;
}

void Model::addTransaction(const Transaction& t)
{
    transactionList.push_back(t);
}

std::vector<int> Model::getYearRange()
{
    std::map<int, bool> present;
    for(auto t : transactionList) {
        auto t_year = t.getDate().year();
        present.insert({t_year, true});
    }

    std::vector<int> range;
    for(auto y : present)
        range.push_back(y.first);

    return range;
}

bool Model::isOnlyIncome() const
{
    for(auto t : transactionList){
        if(t.isOutcome()) return false;
    }

    return true;
}


