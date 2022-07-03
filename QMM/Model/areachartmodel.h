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
    explicit AreaChartModel(Model* baseModel);


    // Calcola solo le categorie presenti nella lista delle transazioni
    void calculateCategories();
    std::vector<Category> getCategories() const;

    void calculateCategoryTotals(Category cat);
    std::map<int, double> getCategoryTotals() const;
    double getMax() const;
};

#endif // AREACHARTMODEL_H
