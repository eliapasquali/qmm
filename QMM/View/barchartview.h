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

    /**
     * @brief Si occupa di predisporre la View con il grafico
     * @return QChartView da inserire nella View
     */
    QChartView* createChart();

    /**
     * @brief Definisce i vari set a partire dalle categorie
     * @param categories vettore delle categorie
     */
    void defineSets(const std::vector<Category>& categories);

    /**
     * @brief Inserisce il valore nella categoria corretta
     * @param set Categoria che indica il set dove inserire
     * @param value Valore da inserire
     */
    void insertInSet(const Category set, const double value);

    /**
     * @brief Inserisce i set nella serie e questa nel grafico
     */
    void insertSeries();

    /**
     * @brief Definisce gli assi del grafico
     */
    void defineAxis();
};

#endif // BARCHARTVIEW_H
