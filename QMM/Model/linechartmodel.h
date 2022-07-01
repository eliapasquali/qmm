#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "model.h"
#include <map>
#include <limits>

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

    void calculateMonthlyTotals();
    std::map<int, double> getMonthlyTotals() const;
    std::pair<double, double> getRange() const;
};

#endif // LINECHARTMODEL_H
