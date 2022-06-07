#include "account.h"

Account::Account()
{
    // prendi transazioni da JSON
}




std::vector<Transaction> Account::splitTransactions(bool type) const
{
    std::vector<Transaction> result;
    for(auto t : transactions) {
        if(type) {
            if(t.getValue() >= 0) result.push_back(t);
        }else if(t.getValue() < 0) result.push_back(t);
    }
    return result;
}


double Account::getTotal(std::vector<Transaction> v) const
{
    return 0; //std::accumulate(v.begin(), v.end(), 0);
}

