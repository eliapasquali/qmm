#include "homemodel.h"

std::vector<Transaction> HomeModel::getTransactionList()
{
    return transactionList;
}

void HomeModel::updateTransactionList(std::vector<Transaction>& toBeAdded)
{
    transactionList.insert(transactionList.end(),
                           toBeAdded.begin(),
                           toBeAdded.end());
}
