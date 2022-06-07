#include "homeview.h"

#include <QHeaderView>
#include <QStringList>
#include <QTextEdit>


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
    }

    // Blocca ridimensionamento in verticale
    buttonsLayout->setStretch(1, 0);

    return buttonsLayout;
}

QGroupBox* HomeView::setupForm()
{
    QGroupBox* form = new QGroupBox;

    // Creo form di inserimento ed elementi
    name = new QLineEdit;
    QDoubleSpinBox* value = new QDoubleSpinBox;
    QLineEdit* category = new QLineEdit;
    QDateEdit* date = new QDateEdit;
    QTextEdit* desc = new QTextEdit;

    // Creo layout del form
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Nome", name);
    formLayout->addRow("Valore", value);
    // Limitate, cambia in select
    formLayout->addRow("Categoria", category);
    formLayout->addRow("Data", date);
    formLayout->addRow("Descrizione", desc);

    form->setLayout(formLayout);


    return form;
}

void HomeView::setupTransactionTable()
{
    movements->setColumnCount(5);
    // righe in base a transazioni ricevute
    // Definizione politiche di espansione
    QHeaderView* movementsHeader = movements->horizontalHeader();
    movementsHeader->setSectionResizeMode(QHeaderView::Stretch);
    QStringList hLabel = { "Nome", "Valore", "Categoria", "Data", "Descrizione" };
    movements->setHorizontalHeaderLabels(hLabel);
}

QLayout* HomeView::insertDataWidgets()
{
    QHBoxLayout* dataWidgets = new QHBoxLayout;

    // Colonna sinistra, con i valori estratti
    QVBoxLayout* leftColumn = new QVBoxLayout;
    QLabel* totalLabel = new QLabel("Prova");
    movements = new QTableWidget();
    setupTransactionTable();

    leftColumn->addWidget(totalLabel);
    leftColumn->addWidget(movements);

    // Colonna destra, per inserimento e salvataggio dei dati
    QVBoxLayout* rightColumn = new QVBoxLayout;
    QPushButton* importBtn  = new QPushButton("Importa movimenti");
    QPushButton* exportBtn  = new QPushButton("Esporta movimenti");
    QPushButton* addBtn     = new QPushButton("Aggiungi movimento");

    rightColumn->addWidget(importBtn);
    rightColumn->addWidget(exportBtn);
    rightColumn->addWidget(setupForm());
    rightColumn->addWidget(addBtn);

    // Unione colonne
    dataWidgets->addItem(leftColumn);
    dataWidgets->addItem(rightColumn);

    connect(importBtn, &QPushButton::clicked, this, &HomeView::importButtonClicked);

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

void HomeView::displayTransaction(std::vector<Transaction> transactionVector){
    int maxRows = transactionVector.size();
    movements->setRowCount(maxRows);
    int row=0;
    for( auto t : transactionVector ) {
        movements->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(t.getName())));
        movements->setItem(row, 1, new QTableWidgetItem(QString::number(t.getValue())));
        movements->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(enumToString.at(t.getCategory()))));
        movements->setItem(row, 3, new QTableWidgetItem(t.getDate().toString("dd/MM/yyyy")));
        movements->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(t.getShort_desc())));
        row++;
    }
}
