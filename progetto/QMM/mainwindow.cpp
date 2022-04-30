#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBoxLayout>
#include <QPushButton>
#include <vector>
#include <iostream>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      auto mainLayout = new QVBoxLayout(this);
//    mainLayout->setSpacing(0);
//    mainLayout->setMargin(0);

//    std::vector<QPushButton*> buttons;

//    QPushButton *b1 = new QPushButton("button1", this);
//    QPushButton *b2 = new QPushButton("button2", this);
//    QPushButton *b3 = new QPushButton("button3", this);

//    buttons.push_back(b1); std::cout << "b1" << std::endl;
//    buttons.push_back(b2); std::cout << "b2" << std::endl;
//    buttons.push_back(b3); std::cout << "b3" << std::endl;

//    int c = 1;
//    for(auto b : buttons) {
//        QString qs = b->text();
//        std::cout<< qs.toStdString() << std::endl;
//        b->setFixedSize(150, 70);
//        mainLayout->insertWidget(c, b);
//        c++;
//    }

//    setLayout(mainLayout);

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    mainLayout->addWidget(button2);
    mainLayout->addWidget(button4);
    mainLayout->addWidget(button3);
    mainLayout->addWidget(button5);
    mainLayout->addWidget(button1);

    setLayout(mainLayout);

    this->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

