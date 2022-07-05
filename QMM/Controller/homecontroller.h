#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "controller.h"
#include "linechartcontroller.h"
#include "barchartcontroller.h"
#include "scatterchartcontroller.h"
#include "piechartcontroller.h"
#include "areachartcontroller.h"
#include "Model/homemodel.h"
#include "Model/linechartmodel.h"
#include "Model/barchartmodel.h"
#include "Model/scatterchartmodel.h"
#include "Model/piechartmodel.h"
#include "Model/areachartmodel.h"
#include "View/homeview.h"
#include "View/linechartview.h"
#include "View/barchartview.h"
#include "View/scatterchartview.h"
#include "View/piechartview.h"
#include "View/areachartview.h"
#include "json_import.h"
#include "json_export.h"

class HomeController : public Controller
{
    Q_OBJECT

private:
    void connectView() const override;

public:
    HomeController(HomeView* v,
                   HomeModel* m = new HomeModel(),
                   Controller* parent = nullptr);
    HomeView* getView() const override;
    HomeModel* getModel() const override;

public slots:
    /**
     * @brief Chiede alla View di inserire la lista, se già presente una
     * la sovrascrive
     */
    void importTransaction();
    /**
     * @brief Esporta la lista di transazioni presenti nella View
     */
    void exportTransaction();
    /**
     * @brief Avvia la creazione di un LineChart
     */
    void createLineChart();
    /**
     * @brief Avvia la creazione di un BarChart
     */
    void createBarChart();
    /**
     * @brief Avvia la creazione di uno ScatterChart
     */
    void createScatterChart();
    /**
     * @brief Avvia la creazione di un PieChart
     */
    void createPieChart();
    /**
     * @brief Avvia la creazione di un AreaChart
     */
    void createAreaChart();
    /**
     * @brief Richiede l'inserimento di una transazione con i
     * dati ottenuti dalla View e la inserisce nel Model
     */
    void insertTransaction(const Transaction& t);
    /**
     * @brief Gestisce l'evento di chiusura
     */
    void onCloseView() const override;

signals:
    /**
     * @brief Invia il segnale alla View che la lista delle transazioni
     * è pronta per essere visualizzata
     * @param p vettore contenente le transazioni da visualizzare
     */
    void checkedTransactionList(const std::vector<Transaction>& p);

};

#endif // HOMECONTROLLER_H
