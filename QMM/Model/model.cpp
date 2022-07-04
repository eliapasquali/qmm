#include "model.h"

Model::Model() {}

void Model::setList(std::vector<Transaction> &tList) {
    transactionList = tList;
}

std::vector<Transaction> Model::getList() const {
    return transactionList;
}

void Model::updateList(std::vector<Transaction> &toBeAdded) {
    transactionList.insert(transactionList.end(),
                           toBeAdded.begin(),
                           toBeAdded.end());
}

void Model::addTransaction(Transaction t)
{
    transactionList.push_back(t);
}

std::pair<int,int> Model::getYearRange()
{
    auto minYear =  std::numeric_limits<int>::max();
    auto maxYear = std::numeric_limits<int>::min();

    for(auto t : transactionList) {
        if(t.getDate().year() < minYear) minYear = t.getDate().year();
        if(t.getDate().year() > maxYear) maxYear = t.getDate().year();
    }

    std::pair<int,int> range({minYear, maxYear});
    return range;
}

