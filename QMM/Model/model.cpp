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

