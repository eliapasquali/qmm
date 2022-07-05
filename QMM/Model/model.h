#ifndef MODEL_H
#define MODEL_H

#include "transaction.h"
#include <vector>

class Model
{

protected:
    std::vector<Transaction> transactionList;

public:
    explicit Model();
    virtual ~Model() = default;

    void setList(const std::vector<Transaction> &tList);
    std::vector<Transaction> getList() const;
    void updateList(const std::vector<Transaction> &toBeAdded);
    void addTransaction(const Transaction& t);
    std::vector<int> getYearRange();

    bool isOnlyIncome() const;
};

#endif // MODEL_H
