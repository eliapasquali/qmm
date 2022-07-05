#ifndef BARCHARTMODEL_H
#define BARCHARTMODEL_H

#include "model.h"
#include "transaction.h"

class BarChartModel : public Model
{

private:

    std::map<Category, bool> categories;

public:
    /**
     * @brief BarChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit BarChartModel(Model* baseModel);

    /**
     * @brief Metodo che calcola le categorie presenti nella lista delle transazioni
     * e il range di valori
     */
    void calculateCategories();
    /**
     * @brief Ritorna le categorie presenti
     * @return vettore delle categorie
     */
    std::vector<Category> getCategories() const;

    /**
     * @brief Calcola i totali mensili per le categorie presenti nell'anno indicato
     * @param cat Categorie di cui calcolare i totali
     * @param year Anno di cui calcolare le spese
     */
    std::map<int, double> calculateMonthlyTotals(const Category cat, const int year) const;
};

#endif // BARCHARTMODEL_H
