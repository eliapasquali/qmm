#include "piechartmodel.h"

PieChartModel::PieChartModel(Model* baseModel)
{
    transactionList = baseModel->getList();
    calculateCategories();
    //stampa();
}
#include <iostream>


void PieChartModel::calculateCategories()
{
    for(auto t : transactionList){
        if(std::find(categories.begin(), categories.end(), t.getCategory()) == categories.end())
            categories.push_back(t.getCategory());
    }

}


std::map<Category, double> PieChartModel::getTotalPerCategories()
{
    std::map<Category, double> totalPerCategories;

    for(auto c : categories) {
        totalPerCategories.insert({c,0});
    }


    for(auto t : transactionList){
        if(t.isOutcome()){
            auto transactionCat = t.getCategory();
            auto transactionValue = t.getValue();

            auto categoria = totalPerCategories.find(transactionCat);
            categoria->second += transactionValue;
        }
    }



    return totalPerCategories;
}



