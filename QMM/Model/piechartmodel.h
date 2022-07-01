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
    explicit PieChartModel(Model* baseModel);

    std::map<Category,double> getTotalPerCategories();

    void calculateCategories();
};

#endif // PIECHARTMODEL_H
