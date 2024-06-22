#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QSize>
#include <QtCore/QDebug>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: #3C6E71;");

    username = new QLabel ("Username: ", this);
    button1 = new QPushButton("Login", this);
    add = new QLineEdit(this);
    password = new QLabel("Password: ", this);
    addpassword = new QLineEdit(this);

    username->setFixedSize(70,30);
    add->setFixedSize(200,30);
    password->setFixedSize(70,30);
    addpassword->setFixedSize(200,30);
    button1->setFixedSize(60,30);


    button1->setStyleSheet("background-color: #62B6CB; color: white;");
    addpassword->setStyleSheet("background-color: #D9D9D9; color: #000000;");
    add->setStyleSheet("color: #000000; background-color: #D9D9D9");
    addpassword->setEchoMode(QLineEdit::Password);

    // central widget and set it
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // vertical layout for central widget
    vLayout = new QVBoxLayout();
    centralWidget->setLayout(vLayout);

    // horizontal layout for username and username linedit
    QHBoxLayout *hLayout = new QHBoxLayout();
    vLayout->addLayout(hLayout);

    // Add buttons to above layout
    hLayout->addWidget(username);
    hLayout->addSpacing(5);
    hLayout->addWidget(add);
    vLayout->addSpacing(5);

    // another horizontal layout for password
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    vLayout->addLayout(hLayout1);
    // add buttons to password horizontal layout
    hLayout1->addWidget(password);
    hLayout1->addSpacing(5);
    hLayout1->addWidget(addpassword);
    vLayout->addSpacing(5);

    // another horizontal layout for login button
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    vLayout->addLayout(hLayout2);

    // added buttons
    hLayout2->addWidget(button1);

    // alignments for layouts
    vLayout->setAlignment(Qt::AlignVCenter);
    hLayout->setAlignment(Qt::AlignHCenter);
    hLayout1->setAlignment(Qt::AlignHCenter);
    hLayout2->setAlignment(Qt::AlignHCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}
