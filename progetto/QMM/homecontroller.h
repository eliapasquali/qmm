#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include <QObject>
#include <mainmodel.h>
#include "homeview.h"
#include "json_import.h"

class homecontroller : public QObject
{
    Q_OBJECT
public:
    explicit homecontroller(QObject *parent = nullptr);

public slots:
    void checkTransactionList();

signals:
    void checkedTransctionList(std::vector<Transaction> p);

private:
    HomeView* homeview;
    MainModel* model;

};

#endif // HOMECONTROLLER_H
