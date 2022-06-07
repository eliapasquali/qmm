#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "transaction.h"
#include <string>
#include <vector>

class Account
{

private:
    double total;
    std::vector<Transaction> transactions;
    std::string owner;

public:
    Account();

    ~Account() = default;

    /**
     * @brief splitTransactions
     * Metodo che estrae tutte le transazioni del tipo desiderato
     * @param type definisce se estrarre le entrate o le uscite
     * @return std::vector contenente le transazioni richieste
     */
    std::vector<Transaction> splitTransactions(bool type) const;

    /**
     * @brief getTotal calcola il totale delle transazioni contenute nel vettore
     * @param v std::vector contenente le transazioni da sommare
     * @return il totale calcolato
     */
    double getTotal(std::vector<Transaction> v) const;

};

#endif // ACCOUNT_H
