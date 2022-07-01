#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "view.h"
#include "transaction.h"

#include <QtCharts>
#include <QLayout>

class BarChartView : public View
{
    Q_OBJECT

private:
    // Elementi
    QChart* barChart;
    QBarSeries* bars;
    std::map<Category, QBarSet*> sets;

    void connectWidgets() const override;

public:
    explicit BarChartView(const QSize& size = QSize(720, 480),
                          const QString& title = QString("Uscite per categoria"),
                          View* parent = nullptr);

    ~BarChartView() = default;

    QChartView* createChart();

    // Funzioni di supporto per la creazione del grafico
    void defineSets(const std::vector<Category>& categories);
    void insertInSet(const Category set, const double value);
    void insertSeries();
    void defineAxis();
};

#endif // BARCHARTVIEW_H
