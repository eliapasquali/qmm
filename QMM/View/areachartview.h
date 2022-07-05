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

    /**
     * @brief Si occupa di predisporre la View con il grafico
     * @return QChartView da inserire nella View
     */
    QChartView* createChart();

    /**
     * @brief Crea un QDialog per selezionare la categoria da visualizzare
     * @return Categoria selezionata
     */
    Category selectCategory(const std::vector<Category>) const;

    /**
     * @brief Definisce le due serie per creare le aree
     */
    void defineSeries();

    /**
     * @brief Inserisce i punti nella upper series
     * @param month Mese del totale
     * @param value Totale del mese
     */
    void insertInSerie(const int month, const double value);

    /**
     * @brief Inserisce le due serie nel grafico
     * @param cat Categoria da cui creare il nome della serie
     */
    void insertSerie(const Category cat);

    /**
     * @brief Definisce gli assi del grafico
     * @param max Massimo totale presente
     */
    void defineAxis(const double max) const;
};

#endif // AREACHARTVIEW_H
