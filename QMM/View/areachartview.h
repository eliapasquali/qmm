#ifndef AREACHARTVIEW_H
#define AREACHARTVIEW_H

#include "view.h"
#include "transaction.h"

#include <QtCharts>
#include <QLayout>
#include <QDialog>

class AreaChartView : public View
{
    Q_OBJECT

private:
    // Elementi
    QChart* areaChart;
    QLineSeries *upper, *lower;
    QAreaSeries* serie;
    void connectWidgets() const override;

public:
    explicit AreaChartView(const QSize& size = QSize(720, 480),
                           const QString& title = QString("Bilanci mensili per categoria"),
                           View* parent = nullptr);

    ~AreaChartView() = default;

    QChartView* createChart();

    // Funzioni di supporto
    Category selectCategory(const std::vector<Category>) const;
    void defineSeries();
    void insertInSerie(const int month, const double value);
    void insertSerie(const Category cat);
    void defineAxis(const double max) const;
};

#endif // AREACHARTVIEW_H
