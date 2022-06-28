#include "controller.h"

Controller::Controller(View* v, Model* m, QWidget *parent)
    : QWidget{parent}, view(v), model(m)
{
    connectToView();
}

void Controller::connectToView() const {
    connect(view,SIGNAL(closeView()),this,SLOT(onCloseView()));
}

Controller::~Controller() {
    setParent(nullptr);
    for(auto child : children()) delete child;
    delete view;
    delete model;
}
