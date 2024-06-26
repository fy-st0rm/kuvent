#include "mainwindow.h"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set background color
    this->setStyleSheet("background-color: #3C6E71;");

    // defining widgets
    logo = new QLabel(this);
    username = new QLabel (this);
    add_username = new QLineEdit(this);
    password = new QLabel(this);
    add_password = new QLineEdit(this);
    notsigned = new QLabel("Don't have an account?", this);
    login_button = new QPushButton("Login", this);
    QObject::connect(login_button, &QPushButton::pressed, this, &MainWindow::onLoginButtonPress);
    createaccount_button = new QPushButton("Create account", this);
    QObject::connect(createaccount_button, &QPushButton::pressed, this, &MainWindow::onCreateAccountPress);

    
    // adding logo of KUvent
    QPixmap loginlogo("assets/images/KUventpng.png");

    logo->setPixmap(loginlogo);
    logo->setFixedSize(300,120);
    logo->setScaledContents(true);

    // adding user png
    QPixmap userpng("assets/images/arroba.png");
    username->setPixmap(userpng);
    username->setScaledContents(true);

    // adding lock png
    QPixmap passpng("assets/images/padlock.png");
    password->setPixmap(passpng);
    password->setScaledContents(true);

    // setting size
    username->setFixedSize(20,18);
    add_username->setFixedSize(200,30);
    password->setFixedSize(20,18);
    add_password->setFixedSize(200,30);
    login_button->setFixedSize(60,30);
    notsigned->setFixedSize(125,30);
    createaccount_button->setFixedSize(100,30);

    //editing the widgets
    add_password->setStyleSheet("background-color: #D9D9D9; color: #000000; border-radius: 5px; padding:5px; ");
    add_username->setStyleSheet("color: #000000; background-color: #D9D9D9; border-radius:5px; padding: 5px; ");
    login_button->setStyleSheet("background-color: #62B6CB; color: white;");
    add_password->setEchoMode(QLineEdit::Password);
    add_password->setPlaceholderText("   Password");
    add_username->setPlaceholderText("   Username");

    // applying drop shadows to lineedit
    applyShadow(add_username);
    applyShadow(add_password);
    applyShadow(login_button);

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
    hLayout2->addWidget(add_username);
    vLayout->addSpacing(10);

    // another horizontal layout for password
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    vLayout->addLayout(hLayout3);
    // add_username buttons to password horizontal layout
    hLayout3->addWidget(password);
    hLayout3->addSpacing(10);
    hLayout3->addWidget(add_password);
    vLayout->addSpacing(10);

    // another horizontal layout for login button
    QHBoxLayout *hLayout4 = new QHBoxLayout();
    vLayout->addLayout(hLayout4);

    // added login buttons
    hLayout4->addWidget(login_button);
    vLayout->setSpacing(5);

    // another horizontal layout for create account button
    QHBoxLayout *hLayout5 = new QHBoxLayout();
    vLayout->addLayout(hLayout5);

    // added a clickable label
    hLayout5->addSpacing(15);
    hLayout5->addWidget(notsigned);
    hLayout5->addSpacing(5);
    hLayout5->addWidget(createaccount_button);



    // alignments for layouts
    vLayout->setAlignment(Qt::AlignVCenter);
    hLayout1->setAlignment(Qt::AlignHCenter);
    hLayout2->setAlignment(Qt::AlignHCenter);
    hLayout3->setAlignment(Qt::AlignHCenter);
    hLayout4->setAlignment(Qt::AlignHCenter);
    hLayout5->setAlignment(Qt::AlignHCenter);

    

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

void MainWindow::applyShadow(QPushButton *pushButton)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(5);
    shadow->setColor("color: #000000");
    shadow->setOffset(1,1);
    pushButton->setGraphicsEffect(shadow);

}


void MainWindow::onLoginButtonPress() {
    QString name = add_username->text();
    QString password = add_password->text();

    // [ ] TODO : make a proper validation and authorization check
    if (name.isEmpty() || password.isEmpty()) {
        QMessageBox::information(this, "Login Error", "Please enter both username and password.");
        return;
    }

    qDebug() << "name =" << name.toStdString().c_str() << "\tpassword =" << password.toStdString().c_str();
    //^^^^^^  remove this in future
}


void MainWindow::onCreateAccountPress(){
    // [ ] TODO : hop to create new account page   
}