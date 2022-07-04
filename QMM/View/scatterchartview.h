#ifndef SCATTERCHARTVIEW_H
#define SCATTERCHARTVIEW_H

#include "view.h"
#include "transaction.h"

#include <QtCharts>
#include <QLayout>

class ScatterChartView : public View
{
    Q_OBJECT

private:
    QChart* scatterChart;
    std::map<Category, QScatterSeries*> series;

    void connectWidgets() const override;

public:
    explicit ScatterChartView(const QSize& size = QSize(720, 480),
                              const QString& title = QString("Spese"),
                              View* parent = nullptr);

    ~ScatterChartView() = default;

    QChartView* createChart();

    // Funzioni di supporto per la creazione del grafico
    void defineSeries(const std::vector<Category>& categories);

    void insertInSerie(const Category serie, const QDate& date, const double value);

    void insertSeries();

    void defineAxis(const std::pair<double, double> &value);
};

#endif // SCATTERCHARTVIEW_H
