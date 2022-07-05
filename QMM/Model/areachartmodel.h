#ifndef AREACHARTMODEL_H
#define AREACHARTMODEL_H

#include "model.h"
#include "transaction.h"

class AreaChartModel : public Model
{

private:
    std::map<int, double> totals;
    std::map<Category, bool> categories;

public:
    /**
     * @brief AreaChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit AreaChartModel(Model* baseModel);


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
    void calculateCategoryTotals(const Category cat, const int year);

    /**
     * @brief Ritorna i totali
     * @return mappa dei totali mensili
     */
    std::map<int, double> getCategoryTotals() const;

    /**
     * @brief Ritorna la spesa mensile massima
     * @return valore massimo
     */
    double getMax() const;
};

#endif // AREACHARTMODEL_H
