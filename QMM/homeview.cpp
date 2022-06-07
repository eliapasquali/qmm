#include "homeview.h"


HomeView::HomeView(QWidget *parent)
    : QWidget{parent}
{
    QLayout* mainLayout = finalLayout();

    setLayout(mainLayout);

}

QLayout* HomeView::insertButtons()
{
    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    std::vector<QPushButton*> buttons;
    QPushButton* graph1 = new QPushButton("Graph 1");
    QPushButton* graph2 = new QPushButton("Graph 2");
    QPushButton* graph3 = new QPushButton("Graph 3");
    QPushButton* graph4 = new QPushButton("Graph 4");
    QPushButton* graph5 = new QPushButton("Graph 5");
    buttons.push_back(graph1);
    buttons.push_back(graph2);
    buttons.push_back(graph3);
    buttons.push_back(graph4);
    buttons.push_back(graph5);

    const QSize BUTTON_SIZE = QSize(150,50);
    for(auto b : buttons){
        b->setFixedSize(BUTTON_SIZE);
        buttonsLayout->addWidget(b);
        connect(b,SIGNAL(clicked()),this,SIGNAL(prova()));
    }

    // Blocca ridimensionamento in verticale
    buttonsLayout->setStretch(1, 0);

    return buttonsLayout;
}

QGroupBox* HomeView::setupForm()
{
    QGroupBox* form = new QGroupBox;

    // Creo form di inserimento ed elementi
    QLineEdit* name = new QLineEdit;
    QDoubleSpinBox* value = new QDoubleSpinBox;
    QLineEdit* category = new QLineEdit;
    QDateEdit* date = new QDateEdit;

    // Creo layout del form
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Nome", name);
    formLayout->addRow("Valore", value);
    // Limitate, cambia in select
    formLayout->addRow("Categoria", category);
    formLayout->addRow("Data", date);

    form->setLayout(formLayout);

     return form;
}

QLayout* HomeView::insertDataWidgets()
{
    QHBoxLayout* dataWidgets = new QHBoxLayout;

    // Colonna sinistra, con i valori estratti
    QVBoxLayout* leftColumn = new QVBoxLayout;
    QLabel* totalLabel = new QLabel("Prova");
    QTableWidget* movements = new QTableWidget();
    leftColumn->addWidget(totalLabel);
    leftColumn->addWidget(movements);

    // Colonna destra, per inserimento e salvataggio dei dati
    QVBoxLayout* rightColumn = new QVBoxLayout;
    QPushButton* importBtn = new QPushButton("Importa movimenti");
    QPushButton* saveBtn = new QPushButton("Salva movimenti");

    rightColumn->addWidget(importBtn);
    rightColumn->addWidget(saveBtn);
    rightColumn->addWidget(setupForm());

    // Unione colonne
    dataWidgets->addItem(leftColumn);
    dataWidgets->addItem(rightColumn);

    return dataWidgets;
}

QLayout* HomeView::finalLayout()
{
    QVBoxLayout* homeLayout = new QVBoxLayout;

    homeLayout->addItem(insertDataWidgets());
    homeLayout->addItem(insertButtons());

    homeLayout->setSpacing(10);
    homeLayout->setMargin(15);

    return homeLayout;
}
