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

#include <iostream>
#include <vector>
#include "transaction.h"

class HomeView : public View
{
    Q_OBJECT

public:
    explicit HomeView(const QSize& size = QSize(1024, 768), const QString& title = QString("QMM"), View* parent = nullptr);
    ~HomeView() = default;

private:

    void connectWidgets() const override;

    // Elementi
    QPushButton *linechart, *barchart, *graph3, *graph4, *graph5, *importBtn, *exportBtn, *addBtn;
    QLineEdit *name, *category;
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
    QLayout* finalLayout();

public slots:
    void displayTransaction(std::vector<Transaction> transactionVector);

signals:
    void importButtonClicked();
    void lineChartClicked();
        void barChartClicked();
};

#endif // HOMEVIEW_H
