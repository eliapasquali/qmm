#include "view.h"

View::View(const QSize &size, const QString& title, View *parent) : QWidget(parent, Qt::Window){
    setSize(size);
    setTitle(title);
}

View::~View() {
    setParent(nullptr);
}

void View::setSize(const QSize& size) {
    resize(size);
}

void View::setTitle(const QString &title) {
    setWindowTitle(title);
}

void View::closeEvent(QCloseEvent *closeEvent) {
    closeEvent->accept();
    emit closeView();
}

// funzione per mostrare messaggi di errore
void View::errorMessage(QString s)
{
    QMessageBox msgBox;
    msgBox.setText(s);
    msgBox.exec();
}
