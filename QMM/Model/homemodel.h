#ifndef HOMEMODEL_H
#define HOMEMODEL_H

#include "model.h"
#include "transaction.h"
#include <vector>
#include <iostream>

class HomeModel : public Model
{

public:
    HomeModel() = default;
    std::vector<Transaction> getTransactionList();
    void updateTransactionList(std::vector<Transaction> &toBeAdded);

private:
    std::vector<Transaction> transactionList;
};

#endif // MAINMODEL_H
