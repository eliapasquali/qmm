#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "model.h"
#include <map>

class LineChartModel : public Model
{

public:
    /**
     * @brief LineChartModel costruisce di copia dal modello della Home
     * @param baseModel modello preso dalla home
     */
    explicit LineChartModel(Model* baseModel);

    std::map<int, double> getMonthlyTotal() const;
};

#endif // LINECHARTMODEL_H
