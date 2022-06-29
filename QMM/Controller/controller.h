#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

#include "View/view.h"
#include "Model/model.h"

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
    virtual void makeVisibile() const;

private:
    virtual void connectView() const;

signals:

public slots:
    virtual void onCloseView() const = 0;
};

#endif // CONTROLLER_H
