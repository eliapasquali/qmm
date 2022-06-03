#include "mainmodel.h"

MainModel::MainModel()
    : multi(4)
{

}

double MainModel::calcolaSpesa(double a, double b)
{
    return (a+b)*multi;
}
