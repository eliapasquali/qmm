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

    /**
     * @brief Si occupa di predisporre la View con il grafico
     * @return QChartView da inserire nella View
     */
    QChart* createChart();

    /**
     * @brief Inserisce il totale per la categoria nella serie
     * @param c Categoria da inserire
     * @param value Valore da inserire
     */
    void addCategories(Category c, const double value);

    /**
     * @brief Inserisce le serie nel grafico
     */
    void insertSeries();

};

#endif // PIECHARTVIEW_H
