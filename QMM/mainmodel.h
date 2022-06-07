#ifndef MAINMODEL_H
#define MAINMODEL_H

#include "transaction.h"
#include "vector"
#include <iostream>

class MainModel
{
public:
    MainModel();
    std::vector<Transaction> getTransactionList();
    void updateTransactionList(std::vector<Transaction> toBeAdded);

private:
    std::vector<Transaction> transactionList;
};

#endif // MAINMODEL_H
