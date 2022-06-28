#include "controller.h"

Controller::Controller(View* v, Model* m, QWidget *parent)
    : QWidget{parent}, view(v), model(m)
{
    connectView();
}

void Controller::connectView() const {
    connect(view,SIGNAL(closeView()),this,SLOT(onCloseView()));
}

void Controller::makeVisibile() const {
    getView()->show();
}

Controller::~Controller() {
    setParent(nullptr);
    for(auto child : children()) delete child;
    delete view;
    delete model;
}
