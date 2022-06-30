#include "piechartview.h"

#include <QVBoxLayout>

void PieChartView::connectWidgets() const
{

}

PieChartView::PieChartView(const QSize &size, const QString &title, View *parent)
{
    QLayout* mainLayout = new QVBoxLayout();

    setLayout(mainLayout);

}
