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

    // Calcola solo le categorie presenti nella lista delle transazioni
    void calculateCategories();
    std::vector<Category> getCategories() const;


    std::map<int, double> calculateMonthlyTotals(Category cat, int year) const;
};

#endif // BARCHARTMODEL_H
