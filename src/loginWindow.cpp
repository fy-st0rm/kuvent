#include "loginWindow.h"

LoginWindow::LoginWindow(QWidget *parent):
    QMainWindow(parent),
    m_ui(new Ui::LoginWindow){

    m_ui->setupUi(this);
    this->setStyleSheet("background-color: #3C6E71;");
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    m_vLayout = new QVBoxLayout();
    centralWidget->setLayout(m_vLayout);

    m_Kuvent_logo = new QLabel(this);
    QPixmap loginlogo("assets/images/KUventpng.png");
    m_Kuvent_logo->setPixmap(loginlogo);
    m_Kuvent_logo->setFixedSize(300,120);
    m_Kuvent_logo->setScaledContents(true);
 
    //horizontal layout for m_Kuvent_logo
    QHBoxLayout *m_hLayout1 = new QHBoxLayout();
    m_vLayout->addLayout(m_hLayout1);
    m_vLayout->addSpacing(1);
    m_vLayout->setAlignment(Qt::AlignVCenter);
    m_hLayout1->addWidget(m_Kuvent_logo);
    m_hLayout1->setAlignment(Qt::AlignHCenter);
    

    m_username = new QLabel (this);
    m_add_username = new QLineEdit(this);
    QPixmap userpng("assets/images/arroba.png");
    m_username->setPixmap(userpng);
    m_username->setScaledContents(true);
    m_username->setFixedSize(20,18);
    m_add_username->setFixedSize(200,30);
    m_add_username->setStyleSheet("color: #000000; background-color: #D9D9D9; border-radius:5px; padding: 5px; ");
    m_add_username->setPlaceholderText("   Username");
    applyShadow(m_add_username);

    // horizontal layout for username
    QHBoxLayout *m_hLayout2 = new QHBoxLayout();
    m_vLayout->addLayout(m_hLayout2);
    m_vLayout->addSpacing(10);
    m_hLayout2->addWidget(m_username);
    m_hLayout2->addSpacing(10);
    m_hLayout2->addWidget(m_add_username);
    m_hLayout2->setAlignment(Qt::AlignHCenter);


    m_password = new QLabel(this);
    m_add_password = new QLineEdit(this);
    QPixmap passpng("assets/images/padlock.png");
    m_password->setPixmap(passpng);
    m_password->setScaledContents(true);
    m_password->setFixedSize(20,18);
    m_add_password->setFixedSize(200,30);
    m_add_password->setStyleSheet("background-color: #D9D9D9; color: #000000; border-radius: 5px; padding:5px; ");
    m_add_password->setEchoMode(QLineEdit::Password);
    m_add_password->setPlaceholderText("   Password");
    applyShadow(m_add_password);

    // another horizontal layout for m_password
    QHBoxLayout *m_hLayout3 = new QHBoxLayout();
    m_vLayout->addLayout(m_hLayout3);
    m_vLayout->addSpacing(10);
    m_hLayout3->addWidget(m_password);
    m_hLayout3->addSpacing(10);
    m_hLayout3->addWidget(m_add_password);
    m_hLayout3->setAlignment(Qt::AlignHCenter);


    m_login_button = new QPushButton("Login", this);
    m_login_button->setFixedSize(60,30);
    m_login_button->setStyleSheet("background-color: #62B6CB; color: white;");
    QObject::connect(m_login_button, &QPushButton::pressed, this, 
                     &LoginWindow::onLoginButtonPress);
    applyShadow(m_login_button);

    //login button
    QHBoxLayout *m_hLayout4 = new QHBoxLayout();
    m_vLayout->addLayout(m_hLayout4);
    m_vLayout->setSpacing(5);
    m_hLayout4->addWidget(m_login_button);
    m_hLayout4->setAlignment(Qt::AlignHCenter);


    m_notsigned = new QLabel("Don't have an account?", this);
    m_notsigned->setFixedSize(125,30);
    m_createaccount_button = new QPushButton("Create account", this);
    m_createaccount_button->setFixedSize(100,30);
    QObject::connect(m_createaccount_button, &QPushButton::pressed, this, 
                     &LoginWindow::onCreateAccountPress);

    // create new account button
    QHBoxLayout *m_hLayout5 = new QHBoxLayout();
    m_vLayout->addLayout(m_hLayout5);
    m_hLayout5->addSpacing(15);
    m_hLayout5->addWidget(m_notsigned);
    m_hLayout5->addSpacing(5);
    m_hLayout5->addWidget(m_createaccount_button);
    m_hLayout5->setAlignment(Qt::AlignHCenter);

}

LoginWindow::~LoginWindow(){
    delete m_ui;
}

// function for applying drop shadows to a widget
void LoginWindow::applyShadow(QWidget *widget) {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(5);
    shadow->setColor(QColor("#000000"));
    // shadow->setOffset(QPointF(1, 1));
    if (qobject_cast<QLineEdit*>(widget)) 
        shadow->setOffset(QPointF(2, 2)); 
    else if (qobject_cast<QPushButton*>(widget)) 
        shadow->setOffset(QPointF(1, 1)); 
    
    widget->setGraphicsEffect(shadow);
}


void LoginWindow::onLoginButtonPress() {
    QString name = m_add_username->text();
    QString m_password = m_add_password->text();

    // [ ] TODO : make a proper validation and authorization check
    if (name.isEmpty() || m_password.isEmpty()) {
        QMessageBox::information(this, "Login Error", "Please enter both username and password.");
        return;
    }

    qDebug() << "name =" << name.toStdString().c_str() << "\tpassword =" << m_password.toStdString().c_str();
    //^^^^^^  remove this in future
}


void LoginWindow::onCreateAccountPress(){
    // [ ] TODO : hop to create new account page   
}
