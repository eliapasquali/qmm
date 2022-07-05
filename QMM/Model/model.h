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
    /**
     * @brief Distruttore virtuale alla base della gerarchia
     */
    virtual ~Model() = default;

    /**
     * @brief Inserisce la lista passata all'interno del Model
     * @param tList lista da inserire
     */
    void setList(const std::vector<Transaction> &tList);

    /**
     * @brief Ritorna la lista presente nel Model
     * @return vettore delle transazioni
     */
    std::vector<Transaction> getList() const;

    /**
     * @brief Aggiunge una transazione al Model
     * @param t Transazione da aggiungere
     */
    void addTransaction(const Transaction& t);

    /**
     * @brief Calcola tutti gli anni delle transazioni presenti
     * @return vettore degli anni
     */
    std::vector<int> getYearRange();

    /**
     * @brief Controlla la tipologia delle transazioni presenti
     * @return true se presenti solo entrate
     */
    bool isOnlyIncome() const;
};

#endif // MODEL_H
