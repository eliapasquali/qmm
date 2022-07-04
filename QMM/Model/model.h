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

    void setList(std::vector<Transaction> &tList);
    std::vector<Transaction> getList() const;
    void updateList(std::vector<Transaction> &toBeAdded);
    void addTransaction(Transaction t);
    std::pair<int, int> getYearRange();
};

#endif // MODEL_H
