#ifndef LINECHARTVIEW_H
#define LINECHARTVIEW_H

#include "view.h"
#include "transaction.h"

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

    // Funzioni di supporto alla creazione del grafico
    // Inserisce punti nella serie corretta
    void insertPoint(const int month, const double value);
    // Inserisce praticamente le serie nel grafico
    void insertSeries();
    void defineAxis(int lastMonth);

};

#endif // LINECHARTVIEW_H
