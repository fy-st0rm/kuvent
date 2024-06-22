#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QSize>
#include <QtCore/QDebug>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>
#include <QtWidgets/QGraphicsDropShadowEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set background color
    this->setStyleSheet("background-color: #3C6E71;");

    // defining widgets
    username = new QLabel (this);
    button1 = new QPushButton("Login", this);
    add = new QLineEdit(this);
    password = new QLabel(this);
    addpassword = new QLineEdit(this);
    logo = new QLabel(this);

    // adding logo of KUvent
    QPixmap loginlogo("C:/tests/KUventpng.png");
    logo->setPixmap(loginlogo);
    logo->setFixedSize(300,120);
    logo->setScaledContents(true);

    // adding user png
    QPixmap userpng("C:/tests/arroba.png");
    username->setPixmap(userpng);
    username->setScaledContents(true);

    // adding lock png
    QPixmap passpng("C:/tests/padlock.png");
    password->setPixmap(passpng);
    password->setScaledContents(true);

    // setting size
    username->setFixedSize(20,18);
    add->setFixedSize(200,30);
    password->setFixedSize(20,18);
    addpassword->setFixedSize(200,30);
    button1->setFixedSize(60,30);

    //editing the widgets
    button1->setStyleSheet("background-color: #62B6CB; color: white;");
    addpassword->setStyleSheet("background-color: #D9D9D9; color: #000000; border-radius: 5px; padding:5px;");
    add->setStyleSheet("color: #000000; background-color: #D9D9D9; border-radius:5px; padding: 5px;");
    addpassword->setEchoMode(QLineEdit::Password);
    addpassword->setPlaceholderText("   Password");
    add->setPlaceholderText("   Username");

    // applying drop shadows to lineedit
    applyShadow(add);
    applyShadow(addpassword);

    // central widget and set it
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // vertical layout for central widget
    vLayout = new QVBoxLayout();
    centralWidget->setLayout(vLayout);

    //horizontal layout for logo
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    vLayout->addLayout(hLayout1);

    // added logo
    hLayout1->addWidget(logo);
    vLayout->addSpacing(1);


    // horizontal layout for username and username linedit
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    vLayout->addLayout(hLayout2);

    // Add buttons to above layout
    hLayout2->addWidget(username);
    hLayout2->addSpacing(10);
    hLayout2->addWidget(add);
    vLayout->addSpacing(10);

    // another horizontal layout for password
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    vLayout->addLayout(hLayout3);
    // add buttons to password horizontal layout
    hLayout3->addWidget(password);
    hLayout3->addSpacing(10);
    hLayout3->addWidget(addpassword);
    vLayout->addSpacing(10);

    // another horizontal layout for login button
    QHBoxLayout *hLayout4 = new QHBoxLayout();
    vLayout->addLayout(hLayout4);

    // added login buttons
    hLayout4->addWidget(button1);

    // alignments for layouts
    vLayout->setAlignment(Qt::AlignVCenter);
    hLayout1->setAlignment(Qt::AlignHCenter);
    hLayout2->setAlignment(Qt::AlignHCenter);
    hLayout3->setAlignment(Qt::AlignHCenter);
    hLayout4->setAlignment(Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// function for applying drop shadows to lineedit
void MainWindow::applyShadow(QLineEdit *lineEdit)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(5);
    shadow->setColor("color: #000000");
    shadow->setOffset(2,2);
    lineEdit->setGraphicsEffect(shadow);

}
