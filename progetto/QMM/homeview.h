#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDateEdit>

#include <iostream>
#include <vector>

class HomeView : public QWidget
{
    Q_OBJECT
public:
    HomeView(QWidget *parent = nullptr);

    ~HomeView() = default;

private:
    // Controller* controller;
    QLineEdit* name;

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
    void cambiaEtichetta(int label);

signals:
    void graph1Clicked();
};

#endif // HOMEVIEW_H
