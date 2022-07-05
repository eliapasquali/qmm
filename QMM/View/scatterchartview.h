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

    /**
     * @brief Si occupa di predisporre la View con il grafico
     * @return QChartView da inserire nella View
     */
    QChartView* createChart();

    /**
     * @brief Definisce le serie in base alle categorie presenti nel Model
     * @param categories vettore delle categorie
     */
    void defineSeries(const std::vector<Category>& categories);

    /**
     * @brief Aggiunge il punto (date, value) nella serie corretta
     * @param serie Serie in cui aggiungere
     * @param date Data della transazione
     * @param value Valore della transazione
     */
    void insertInSerie(const Category serie, const QDate& date, const double value);

    /**
     * @brief Inserisce le serie in scatterChart
     */
    void insertSeries();

    /**
     * @brief Definisce gli assi del grafico, con il range di valori corretto
     * @param value pair contenente il range dei valori
     */
    void defineAxis(const std::pair<double, double> &value);
};

#endif // SCATTERCHARTVIEW_H
