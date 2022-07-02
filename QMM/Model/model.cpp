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

