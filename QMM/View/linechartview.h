#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H

#include "view.h"

#include <QtCharts>
#include <QLayout>
#include <QLineSeries>

class LineChartView : public View
{
    Q_OBJECT

private:
    QChart* lineChart;
    QLineSeries* dataSeries;

    void connectWidgets() const override;

public:
    explicit LineChartView(const QSize& size = QSize(720, 480), const QString& title = QString("QMM"), View* parent = nullptr);
    ~LineChartView() = default;

    QChartView* createChart();
};

#endif // LINECHARTVIEW_H
