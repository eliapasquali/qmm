#include "homeview.h"

HomeView::HomeView(const QSize& size, const QString& title, View* parent) :
    View(size, title, parent)
{
    QLayout* mainLayout = finalLayout();

    setLayout(mainLayout);

    connectWidgets();
}

void HomeView::connectWidgets() const {
    connect(importBtn, &QPushButton::clicked,
            this, &HomeView::importButtonClicked);
    connect(linechart, &QPushButton::clicked,
            this, &HomeView::lineChartClicked);
    connect(barchart, &QPushButton::clicked,
            this, &HomeView::barChartClicked);
    connect(scatterchart, &QPushButton::clicked,
            this, &HomeView::scatterChartClicked);
    connect(pieChartBtn, &QPushButton::clicked,
            this, &HomeView::pieChartClicked);
}

QLayout* HomeView::insertButtons()
{
    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    std::vector<QPushButton*> buttons;
    linechart = new QPushButton("Andamento\nperiodico");
    barchart = new QPushButton("Uscite per\ncategoria");
    pieChartBtn = new QPushButton("Spese per tipologia");
    scatterchart = new QPushButton("Tutte le\n transazioni");
    graph5 = new QPushButton("Graph 5");
    buttons.push_back(linechart);
    buttons.push_back(barchart);
    buttons.push_back(pieChartBtn);
    buttons.push_back(scatterchart);
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
    value = new QDoubleSpinBox;
    category = new QLineEdit;
    date = new QDateEdit;
    short_desc = new QTextEdit;

    // Creo layout del form
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Nome", name);
    formLayout->addRow("Valore", value);
    // Limitate, cambia in select
    formLayout->addRow("Categoria", category);
    formLayout->addRow("Data", date);
    formLayout->addRow("Descrizione", short_desc);

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
    importBtn  = new QPushButton("Importa movimenti");
    exportBtn  = new QPushButton("Esporta movimenti");
    addBtn     = new QPushButton("Aggiungi movimento");

    rightColumn->addWidget(importBtn);
    rightColumn->addWidget(exportBtn);
    rightColumn->addWidget(setupForm());
    rightColumn->addWidget(addBtn);

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

void HomeView::displayTransaction(std::vector<Transaction> transactionVector){
    int maxRows = transactionVector.size();
    movements->setRowCount(maxRows);
    int row=0;
    for( auto t : transactionVector ) {
        movements->setItem(row, 0, new QTableWidgetItem(t.getName()));
        movements->setItem(row, 1, new QTableWidgetItem(QString::number(t.getValue())));
        movements->setItem(row, 2, new QTableWidgetItem(enumToString.at(t.getCategory())));
        movements->setItem(row, 3, new QTableWidgetItem(t.getDate().toString("dd/MM/yyyy")));
        movements->setItem(row, 4, new QTableWidgetItem(t.getShort_desc()));
        row++;
    }
}
