#include "Application/Application.h"
#include "SignupPage.h"

void SignupPage::onAttach() {

    getBaseWidget()->setStyleSheet("background-color: #3C6E71;");

	// Creating main layout of this page
	m_vLayout2 = new QVBoxLayout;

	// Applying that main layout to the page
	setLayout(m_vLayout2);

    create_account_title = new QLabel("Create new Account", this);
    create_account_title->setFixedSize(220, 50);
    create_account_title->setStyleSheet("font-size: 16pt; color: #FFFFFF; font-weight: bold; letter-spacing: 1px;");

    username2 = new QLabel(this);
    add_username2 = new QLineEdit(this);
    username2->setFixedSize(20, 18);
    add_username2->setFixedSize(200, 30);
    add_username2->setStyleSheet(
        "color: #000000;"
        "background-color: #D9D9D9;"
        "border-radius: 5px;"
        "padding: 5px;"
        );
    add_username2->setPlaceholderText("Username");
    QPixmap userpng("assets/images/arroba.png");
    username2->setPixmap(userpng);
    username2->setScaledContents(true);
    applyShadow(add_username2);

    email = new QLabel(this);
    add_email = new QLineEdit(this);
    email->setFixedSize(20, 18);
    QPixmap profilepng("assets/images/user.png");
    email->setPixmap(profilepng);
    email->setScaledContents(true);
    add_email->setFixedSize(200, 30);
    add_email->setStyleSheet(
        "color: #000000;"
        "background-color: #D9D9D9;" 
        "border-radius: 5px;"
        "padding: 5px;"
        );
    add_email->setPlaceholderText("Email");
    applyShadow(add_email);

    password2 = new QLabel(this);
    password2->setFixedSize(20,18);
    QPixmap passpng("assets/images/padlock.png");
    password2->setPixmap(passpng);
    password2->setScaledContents(true);

    add_password2 = new PasswordLineEdit(this);
    add_password2->setFixedSize(200, 30);
    add_password2->setStyleSheet(
        "color: #000000;"
        "background-color: #D9D9D9;"
        "border-radius: 5px;" 
        "padding: 5px;"
        );
    add_password2->setPlaceholderText("Password");
    applyShadow(add_password2);

    confirm_password2 = new QLabel(this);
    confirm_password2->setFixedSize(20,18);
    QPixmap confirm_passpng("assets/images/reset-password.png");
    confirm_password2->setPixmap(confirm_passpng);
    confirm_password2->setScaledContents(true);

    add_confirmpassword2 = new PasswordLineEdit(this);
    add_confirmpassword2->setFixedSize(200, 30);
    add_confirmpassword2->setStyleSheet(
        "color: #000000;"
        "background-color: #D9D9D9;" 
        "border-radius: 5px;" 
        "padding: 5px;"
        );
    add_confirmpassword2->setPlaceholderText("Confirm Password");
    applyShadow(add_confirmpassword2);

    account_type = new QLabel("Account Type : ", this);
    account_type->setFixedSize(80,30);
    account_type->setStyleSheet("color : #FFFFFF;");

    select_account_type = new QComboBox(this);
    select_account_type->setFixedSize(100,30);
    select_account_type->setStyleSheet(
        "color: #000000;"
        "background-color: #D9D9D9;" 
        "border-radius:5px;"
        "padding: 5px;"
        );
    select_account_type->addItem("Participant");
    select_account_type->addItem("Organizer");
    applyShadow(select_account_type);

    signupButton = new QPushButton("Signup", this);
    signupButton->setFixedSize(60,30);
    signupButton->setStyleSheet("background-color: #62B6CB; color: white;");
    applyShadow(signupButton);

    go_tologin = new QLabel("Already have an account?", this);
    go_tologin->setFixedSize(135,30);

    login_now = new QLabel("<a href= \"LoginPage\" style = \"color: #62B6CB; text-decoration: none;\"> Login now </a>");
    login_now->setFixedSize(80,30);
    login_now->setStyleSheet(
        "padding: 5px;"
    );
	connect(
		login_now,
		&QLabel::linkActivated,
		this,
		&SignupPage::onLoginNowPress
	);


    QHBoxLayout *m_hLayout6 = new QHBoxLayout();
    m_hLayout6->addWidget(create_account_title);
    m_vLayout2->addLayout(m_hLayout6);
    m_vLayout2->setAlignment(Qt::AlignVCenter);
    m_hLayout6->setAlignment(Qt::AlignHCenter);

    QHBoxLayout *m_hLayout7 = new QHBoxLayout();
    m_hLayout7->addWidget(username2);
    m_hLayout7->addSpacing(10);
    m_hLayout7->addWidget(add_username2);
    m_vLayout2->addLayout(m_hLayout7);
    m_hLayout7->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout8 = new QHBoxLayout();
    m_hLayout8->addWidget(email);
    m_hLayout8->addSpacing(10);
    m_hLayout8->addWidget(add_email);
    m_vLayout2->addLayout(m_hLayout8);
    m_hLayout8->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout9 = new QHBoxLayout();
    m_hLayout9->addWidget(password2);
    m_hLayout9->addSpacing(10);
    m_hLayout9->addWidget(add_password2);
    m_vLayout2->addLayout(m_hLayout9);
    m_hLayout9->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout10 = new QHBoxLayout();
    m_hLayout10->addWidget(confirm_password2);
    m_hLayout10->addSpacing(10);
    m_hLayout10->addWidget(add_confirmpassword2);
    m_vLayout2->addLayout(m_hLayout10);
    m_hLayout10->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout11 = new QHBoxLayout();
    m_hLayout11->addWidget(account_type);
    m_hLayout11->addSpacing(10);
    m_hLayout11->addWidget(select_account_type);
    m_vLayout2->addLayout(m_hLayout11);
    m_hLayout11->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout12 = new QHBoxLayout();
    m_hLayout12->addWidget(signupButton);
    m_vLayout2->addLayout(m_hLayout12);
    m_hLayout12->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout13 = new QHBoxLayout();
    m_hLayout13->addWidget(go_tologin);
    m_hLayout13->addSpacing(1);
    m_hLayout13->addWidget(login_now);
    m_vLayout2->addLayout(m_hLayout13);
    m_hLayout13->setAlignment(Qt::AlignHCenter);
    m_vLayout2->setSpacing(10);


}

void SignupPage::applyShadow(QWidget *widget)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
	shadow->setBlurRadius(5);
	shadow->setColor(QColor("#000000"));
	// shadow->setOffset(QPointF(1, 1));
	if (qobject_cast<QLineEdit*>(widget)) 
		shadow->setOffset(QPointF(2, 2)); 
	else if (qobject_cast<QPushButton*>(widget)) 
		shadow->setOffset(QPointF(1, 1));
    else if (qobject_cast<QComboBox*>(widget)) 
		shadow->setOffset(QPointF(1, 1));  
	
	widget->setGraphicsEffect(shadow);
}

void SignupPage::onLoginNowPress() {
	/* Here switchPage function changes the page 
	 * according to the assigned name
	 * (named assigned while doing addPage)
	 */
	app->switchPage("LoginPage");
}
