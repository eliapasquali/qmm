#include "piechartview.h"


void PieChartView::connectWidgets() const
{

}

PieChartView::PieChartView(const QSize &size, const QString &title, View *parent)
    : View(size, title, parent)
{
    QLayout* mainLayout = new QVBoxLayout();

    QChartView* chartView = new QChartView(createChart());

    mainLayout->addWidget(chartView);

    setLayout(mainLayout);

}

QChart* PieChartView::createChart()
{

    series = new QPieSeries();

    chart = new QChart();

    chart->setTitle("Spesa per categoria");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    return chart;
}



void PieChartView::addCategories(Category c, double value)
{
    auto catIter = enumToString.find(c);
    QString catName = catIter->second;

    series->append(catName,value);
}

void PieChartView::insertSeries()
{
    chart->addSeries(series);
}



