#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "model.h"
#include <limits>
#include <cmath>

class LineChartModel : public Model
{

private:
    std::map<int, double> totals;

public:
    /**
     * @brief LineChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit LineChartModel(Model* baseModel);

    /**
     * @brief Calcola i totali mensili nell'anno indicato
     * @param year Anno di cui calcolare le spese
     */
    std::map<int, double> calculateMonthlyTotals(const int year);

    /**
     * @brief Ritorna i totali calcolati
     * @return map dei totali mensili
     */
    std::map<int, double> getMonthlyTotals() const;

    /**
     * @brief Massimo e minimo arrotondati alle migliaia
     * @return pair con minimo e massimo
     */
    std::pair<double, double> getRange() const;
};

#endif // LINECHARTMODEL_H
