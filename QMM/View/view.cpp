#include "view.h"

View::View(const QSize &size, const QString& title, View *parent) : QWidget(parent, Qt::Window){
    setSize(size);
    setTitle(title);
}

void View::setYear(const std::vector<int>& range)
{
    QStringList yearList;
    for(int y : range) yearList.append(QString::number(y));

    bool ok=false;
    QString dialogResult = QInputDialog::getItem(this,
                                                 "Seleziona anno",
                                                 "Anno",
                                                 yearList, 0, false, &ok);
    year = *range.begin(); // Default al primo anno del range
    if(ok && !dialogResult.isEmpty())
        year = dialogResult.toInt();
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

int View::getYear() const
{
    return year;
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
