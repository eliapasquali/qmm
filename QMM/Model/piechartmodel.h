#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include "model.h"
#include <iostream>
#include <algorithm>    // mi serve per avere il metodo find sui vettori

class PieChartModel : public Model
{
private:
    std::vector<Category> categories;


public:
    /**
     * @brief PieChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit PieChartModel(Model* baseModel);

    /**
     * @brief Calcola i totali mensili per le categorie presenti nell'anno indicato
     * @param year Anno di cui calcolare le spese
     */
    std::map<Category,double> getTotalPerCategories(const int year) const;

    /**
     * @brief Calcola le categorie presenti nella transazioni
     */
    void calculateCategories();
};

#endif // PIECHARTMODEL_H
