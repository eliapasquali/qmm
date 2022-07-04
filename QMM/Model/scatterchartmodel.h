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

    void calculateAllAttributes();

    std::vector<Category> getCategories() const;
    std::pair<double, double> getValueRange() const;
};

#endif // SCATTERCHARTMODEL_H
