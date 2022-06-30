#include "linechartview.h"

void LineChartView::connectWidgets() const {}

LineChartView::LineChartView(const QSize& size, const QString& title, View* parent)
    : View(size, title, parent)
{
    auto layout = new QVBoxLayout();

    auto chartView = createChart();

    layout->addWidget(chartView);

    setLayout(layout);

    connectWidgets();
}

QChartView* LineChartView::createChart() {
    lineChart = new QChart();
    lineChart->setTitle("Andamento del saldo nel tempo");
    lineChart->legend()->setVisible(false);

    dataSeries = new QLineSeries();

    auto view = new QChartView(lineChart, this);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}

void LineChartView::insertPoint(const int month, const double value) {
    dataSeries->append(month, value);
}

void LineChartView::insertSeries() {
    lineChart->addSeries(dataSeries);
}

void LineChartView::defineAxis(int lastMonth) {

    auto axisX = new QValueAxis();
    axisX->setTitleText("Mese");
    axisX->setRange(1, lastMonth);
    axisX->setLabelFormat("%d");
    axisX->setTickCount(lastMonth);
    lineChart->addAxis(axisX, Qt::AlignBottom);
    dataSeries->attachAxis(axisX);

    auto axisY = new QValueAxis();
    axisY->setTitleText("Saldo");
    //axisY->setTickInterval(500);
    lineChart->addAxis(axisY, Qt::AlignLeft);

    dataSeries->attachAxis(axisY);
}
