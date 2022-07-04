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
    connect(exportBtn, &QPushButton::clicked,
            this, &HomeView::exportButtonClicked);
    connect(linechart, &QPushButton::clicked,
            this, &HomeView::lineChartClicked);
    connect(barchart, &QPushButton::clicked,
            this, &HomeView::barChartClicked);
    connect(scatterchart, &QPushButton::clicked,
            this, &HomeView::scatterChartClicked);
    connect(pieChartBtn, &QPushButton::clicked,
            this, &HomeView::pieChartClicked);
    connect(areaChart, &QPushButton::clicked,
            this, &HomeView::areaChartClicked);
    connect(addBtn, &QPushButton::clicked,
            this, &HomeView::createTransaction);

}

QLayout* HomeView::insertButtons()
{
    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    std::vector<QPushButton*> buttons;
    linechart = new QPushButton("Andamento\nperiodico");
    barchart = new QPushButton("Uscite per\ncategoria");
    pieChartBtn = new QPushButton("Spese per tipologia");
    scatterchart = new QPushButton("Tutte le\ntransazioni");
    areaChart = new QPushButton("Uscite mensili\nper categoria");
    buttons.push_back(linechart);
    buttons.push_back(barchart);
    buttons.push_back(pieChartBtn);
    buttons.push_back(scatterchart);
    buttons.push_back(areaChart);

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
    value->setMaximum(1000000); // Limite al valore
    category = new QComboBox;
    type = new QComboBox;
    date = new QDateEdit;
    date->setDisplayFormat("dd/MM/yyyy"); // Formato italiano per inserimento data
    short_desc = new QTextEdit;

    //setto i valori del menu a tendina di category
    category->addItem("Lavoro");
    category->addItem("Casa");
    category->addItem("Intrattenimento");
    category->addItem("Salute");
    category->addItem("Risparmi");
    category->addItem("Tasse");

    //setto i valori del menu a tendina di type
    type->addItem("Spesa");
    type->addItem("Introito");

    // Creo layout del form
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Nome", name);
    formLayout->addRow("Type", type);
    formLayout->addRow("Valore", value);
    // Limitate, cambia in select
    formLayout->addRow("Categoria", category);
    formLayout->addRow("Data", date);
    formLayout->addRow("Descrizione", short_desc);


    // Bottone per l'inserimento della transazione
    addBtn = new QPushButton("Aggiungi movimento");
    addBtn->setFixedSize(300,50);

    // layout del bottone per l0'inserimento della transizione
    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    buttonsLayout->setContentsMargins(25,20,12,50);
    buttonsLayout->setAlignment(Qt::AlignCenter);
    buttonsLayout->addWidget(addBtn);


    formLayout->addRow(buttonsLayout);

    form->setLayout(formLayout);

    return form;
}

void HomeView::setupTransactionTable()
{
    movements->setColumnCount(5);
    // righe in base a transazioni ricevute
    // Definizione politiche di espansione
    QHeaderView* movementsHeader = movements->horizontalHeader();
    movementsHeader->setSectionResizeMode(QHeaderView::Interactive);
    QStringList hLabel = { "Nome", "Valore", "Categoria", "Data", "Descrizione" };
    movements->setHorizontalHeaderLabels(hLabel);
}

QLayout* HomeView::insertDataWidgets()
{
    QHBoxLayout* dataWidgets = new QHBoxLayout;

    // Colonna sinistra, con i valori estratti
    QLabel* listaMov = new QLabel("Lista movimenti");
    QVBoxLayout* leftColumn = new QVBoxLayout;
    movements = new QTableWidget();
    setupTransactionTable();

    leftColumn->addWidget(listaMov);
    leftColumn->addWidget(movements);

    // Colonna destra, per inserimento e salvataggio dei dati
    QVBoxLayout* rightColumn = new QVBoxLayout;
    QLabel* inserimMov = new QLabel("Inserimento transazione");

    rightColumn->addWidget(inserimMov);
    rightColumn->addWidget(setupForm());
    rightColumn->setContentsMargins(10,5,0,0);

    // Unione colonne
    dataWidgets->addItem(leftColumn);
    dataWidgets->addItem(rightColumn);

    return dataWidgets;
}

QLayout *HomeView::importExportButtonLayout()
{
    QHBoxLayout* importExportLayout = new QHBoxLayout;

    importBtn  = new QPushButton("Importa movimenti");
    exportBtn  = new QPushButton("Esporta movimenti");

    importExportLayout->addWidget(importBtn);
    importExportLayout->addWidget(exportBtn);

    return importExportLayout;
}

QLayout* HomeView::finalLayout()
{
    QVBoxLayout* homeLayout = new QVBoxLayout;

    homeLayout->addItem(importExportButtonLayout());
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
        movements->setItem(row, 4, new QTableWidgetItem(t.getShortDesc()));
        row++;
    }
}

// funzione che crea la transazione prendendo i valori dal form e la passa allo slot insertTransaction del homecontroller
void HomeView::createTransaction()
{
    if(!name->text().isEmpty()){
        auto t_cat = static_cast<Category>(category->currentIndex());
        bool spesa = type->currentText().toStdString() == "Spesa";

        Transaction t(name->text(), value->value(), date->date(), t_cat, spesa, short_desc->toPlainText());

        emit createdTransaction(t);
    }
    else
        errorMessage("Necessario un nome per inserire la transazione");

}
