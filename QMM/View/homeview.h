#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include "view.h"
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QGroupBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QLabel>

#include <QComboBox>
#include <vector>
#include "transaction.h"

class HomeView : public View
{
    Q_OBJECT

public:
    explicit HomeView(const QSize& size = QSize(1280, 720), const QString& title = QString("QMM"), View* parent = nullptr);
    ~HomeView() = default;

private:

    void connectWidgets() const override;

    // Elementi
    QPushButton *linechart, *barchart, *pieChartBtn, *scatterchart, *areaChart, *importBtn, *exportBtn, *addBtn;
    QLineEdit *name;
    QComboBox *category, *type;
    QDateEdit *date;
    QTextEdit *short_desc;
    QDoubleSpinBox *value;
    QTableWidget *movements;


    /**
     * @brief insertButtons crea la parte di home contenente i bottoni
     * @return layout contenente i bottoni per richiamare i grafici
     */
     QLayout* insertButtons();

     /**
      * @brief setupFrom funzione ausiliaria per costruire il form di
      * inserimento nuovi movimenti
      * @return ritorna il widget QGroupBox del form
      */
     QGroupBox* setupForm();

     /**
      * @brief setupTransactionTable Configura impostazioni grafiche TableWidget
      */
     void setupTransactionTable();

     /**
     * @brief insertData crea la griglia con lista movimenti e strumenti
     * per aggiugnerli, importarli e salvarli
     * @return layout della parte superiore della home, contenente gli
     * elementi legati ai dati
     */
    QLayout* insertDataWidgets();

    /**
     * @brief mixLayout unisce i vari layout per creare quello
     * finale della home
     * @return layout completo della home
     */

    QLayout* importExportButtonLayout();



    QLayout* finalLayout();

public slots:
    void displayTransaction(const std::vector<Transaction> &transactionVector);
    void createTransaction();

signals:
    void importButtonClicked();
    void exportButtonClicked();
    void addButtonClicked();
    void deleteButtonClicked(int indexTransaction);

    void lineChartClicked();
    void barChartClicked();
    void scatterChartClicked();
    void pieChartClicked();
    void areaChartClicked();
    void createdTransaction(const Transaction& t);
};

#endif // HOMEVIEW_H
