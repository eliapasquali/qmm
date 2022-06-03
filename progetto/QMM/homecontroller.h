#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include <QObject>
#include <mainmodel.h>
#include "homeview.h"

class homecontroller : public QObject
{
    Q_OBJECT
public:
    explicit homecontroller(QObject *parent = nullptr);

public slots:
    void calcolaNumero();

signals:

    void calcolatoNumero(int numero);

private:
    HomeView* homeview;
    MainModel* model;

};

#endif // HOMECONTROLLER_H
