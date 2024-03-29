#ifndef SCATTERCHARTMODEL_H
#define SCATTERCHARTMODEL_H

#include "model.h"
#include <cmath>


class ScatterChartModel : public Model
{

private:
    std::map<Category, bool> categories;
    std::pair<double, double> valueRange;

public:
    /**
     * @brief ScatterChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit ScatterChartModel(Model* baseModel);

    /**
     * @brief Metodo che calcola le categorie presenti nella lista delle transazioni
     * e il range di valori
     */
    void calculateAllAttributes();

    /**
     * @brief Ritorna le categorie presenti
     * @return vettore delle categorie
     */
    std::vector<Category> getCategories() const;
    /**
     * @brief Ritorna il range di valori
     * @return pair del range
     */
    std::pair<double, double> getValueRange() const;
};

#endif // SCATTERCHARTMODEL_H
