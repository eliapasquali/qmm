#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "view.h"
#include "transaction.h"

#include <QVBoxLayout>
#include <QtCharts>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>


class PieChartView : public View
{
    Q_OBJECT

private:
    void connectWidgets() const override;
    QPieSeries* series;
    QChart* chart;


public:
    explicit PieChartView(const QSize& size = QSize(720, 480), const QString& title = QString("QMM"), View* parent = nullptr);
    ~PieChartView() = default;

    QChart* createChart();
    void addCategories(Category c, const double value);
    void insertSeries();

};

#endif // PIECHARTVIEW_H
