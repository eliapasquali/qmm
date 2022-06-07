#include "mainmodel.h"

MainModel::MainModel(){

}

std::vector<Transaction> MainModel::getTransactionList()
{
    return transactionList;
}

void MainModel::updateTransactionList(std::vector<Transaction> toBeAdded)
{
    transactionList.insert(transactionList.end(), toBeAdded.begin(),toBeAdded.end());
}
