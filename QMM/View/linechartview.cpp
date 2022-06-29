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
    lineChart->setTitle("Andamento delle spese nel tempo");

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
    lineChart->createDefaultAxes();
    lineChart->axisX()->setTitleText("Mese");
    lineChart->axisY()->setTitleText("Spesa");
}
