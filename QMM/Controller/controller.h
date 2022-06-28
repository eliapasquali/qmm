#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

#include "View/view.h"
#include "Model/model.cpp"

class Controller : public QWidget
{
    Q_OBJECT
public:

    View* view;
    Model* model;

    explicit Controller(View* v, Model* m, QWidget *parent = nullptr);
    virtual ~Controller();

    virtual View* getView() const = 0;
    virtual Model* getModel() const = 0;

private:
    virtual void connectToView() const;
signals:

public slots:
    virtual void onCloseView() const = 0;
};

#endif // CONTROLLER_H
