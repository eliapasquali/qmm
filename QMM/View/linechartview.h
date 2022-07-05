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
    QLineSeries *dataSeries;

    void connectWidgets() const override;

public:
    explicit LineChartView(const QSize& size = QSize(720, 480),
                           const QString& title = QString("QMM"),
                           View* parent = nullptr);

    ~LineChartView() = default;

    /**
     * @brief Si occupa di predisporre la View con il grafico
     * @return QChartView da inserire nella View
     */
    QChartView* createChart();

    /**
     * @brief Inserisce i punti nella serie
     * @param month Mese da inserire
     * @param value Totale del mese
     */
    void insertPoint(const int month, const double value);

    /**
     * @brief Inserisce la serie nel grafico
     */
    void insertSeries();

    /**
     * @brief Definisce gli assi del grafico, con limiti corretti
     * @param lastMonth Ultimo punto su asse x
     * @param min Minimo per asse y
     * @param max Massimo per asse y
     */
    void defineAxis(const int lastMonth, const double min, const double max);

};

#endif // LINECHARTVIEW_H
