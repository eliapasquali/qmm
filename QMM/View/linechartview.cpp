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

QChartView* LineChartView::createChart(){
    lineChart = new QChart();
    lineChart->setTitle("Andamento delle spese nel tempo");
    lineChart->legend()->setVisible(true);
    lineChart->legend()->setAlignment(Qt::AlignBottom);

    dataSeries = new QLineSeries();
    dataSeries->append(0, 6);
    dataSeries->append(2, 4);
    dataSeries->append(4, 8);
    dataSeries->append(6, 4);
    dataSeries->append(10, 5);
    lineChart->addSeries(dataSeries);


    lineChart->createDefaultAxes();
    lineChart->axisX()->setTitleText("Periodo");
    lineChart->axisY()->setTitleText("Spesa");

    auto view = new QChartView(lineChart, this);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}
