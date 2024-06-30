#include "Application/Application.h"
#include "SignupPage.h"

void SignupPage::onAttach() {
	// Creating main layout of this page
	m_vLayout2 = new QVBoxLayout;

	// Applying that main layout to the page
	setLayout(m_vLayout2);

	getBaseWidget()->setStyleSheet("background-color: #3C6E71;");

    create_account_title = new QLabel("Create new Account", this);
    create_account_title->setFixedSize(220, 50);
    create_account_title->setStyleSheet("font-size: 16pt; color: #FFFFFF; font-weight: bold; letter-spacing: 1px;");

    username2 = new QLabel(this);
    username2->setFixedSize(20, 18);
    add_username2 = new QLineEdit(this);
    add_username2->setFixedSize(200, 30);
    add_username2->setStyleSheet("background-color: #D9D9D9; border-radius: 5px; padding: 5px;");
    add_username2->setPlaceholderText("Username");
    QPixmap userpng("assets/images/arroba.png");
    username2->setPixmap(userpng);
    username2->setScaledContents(true);

    email = new QLabel(this);
    email->setFixedSize(20, 18);
    QPixmap profilepng("assets/images/user.png");
    email->setPixmap(profilepng);
    email->setScaledContents(true);
    add_email = new QLineEdit(this);
    add_email->setFixedSize(200, 30);
    add_email->setStyleSheet("background-color: #D9D9D9; border-radius: 5px; padding: 5px;");
    add_email->setPlaceholderText("Email");

    password2 = new QLabel(this);
    password2->setFixedSize(20,18);
    QPixmap passpng("assets/images/padlock.png");
    password2->setPixmap(passpng);
    password2->setScaledContents(true);

    add_password2 = new PasswordLineEdit(this);
    add_password2->setFixedSize(200, 30);
    add_password2->setStyleSheet("background-color: #D9D9D9; border-radius: 5px; padding: 5px;");
    add_password2->setPlaceholderText("Password");

    confirm_password2 = new QLabel(this);
    confirm_password2->setFixedSize(20,18);
    QPixmap confirm_passpng("assets/images/reset-password.png");
    confirm_password2->setPixmap(confirm_passpng);
    confirm_password2->setScaledContents(true);

    add_confirmpassword2 = new PasswordLineEdit(this);
    add_confirmpassword2->setFixedSize(200, 30);
    add_confirmpassword2->setStyleSheet("background-color: #D9D9D9; border-radius: 5px; padding: 5px;");
    add_confirmpassword2->setPlaceholderText("Confirm Password");

    account_type = new QLabel("Account Type : ", this);
    account_type->setFixedSize(80,30);
    account_type->setStyleSheet("color : #FFFFFF;");

    select_account_type = new QComboBox(this);
    select_account_type->setFixedSize(100,30);
    select_account_type->setStyleSheet("background-color: #D9D9D9; border-radius:5px; padding: 5px;");
    select_account_type->addItem("Participant");
    select_account_type->addItem("Organizer");

    signupButton = new QPushButton("Signup", this);
    signupButton->setFixedSize(60,30);
    signupButton->setStyleSheet(
        "background-color: #62B6CB;"
        "border-radius: 5px;"
        "padding: 5px;"
        "color: white;"
    );

    go_tologin = new QLabel("Already have an account?", this);
    go_tologin->setFixedSize(135,30);

    login_now = new QPushButton("Login now", this);
    login_now->setFixedSize(80,30);
    login_now->setStyleSheet("color : #62B6CB;");
	connect(
		login_now,
		&QPushButton::pressed,
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
    m_hLayout13->addSpacing(10);
    m_hLayout13->addWidget(login_now);
    m_vLayout2->addLayout(m_hLayout13);
    m_hLayout13->setAlignment(Qt::AlignHCenter);
    m_vLayout2->setSpacing(10);


}

PasswordLineEdit::PasswordLineEdit(QWidget *parent) : QLineEdit(parent), password2Visible(false)
{
    this->setEchoMode(QLineEdit::Password);

    eyeButton = new QToolButton(this);
    eyeButton->setIcon(QIcon("assets/images/eye.png"));
    eyeButton->setIconSize(QSize(25, 25));
    eyeButton->setCursor(Qt::PointingHandCursor);
    eyeButton->setToolTip("Show Password");
    eyeButton->setStyleSheet("border: none; padding: 0px;");
    eyeButton->setFixedSize(20, 20);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(eyeButton, 0, Qt::AlignRight);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 5, 0);
    setLayout(layout);

    connect(eyeButton, &QToolButton::clicked, this, &PasswordLineEdit::togglePasswordVisibility);
}

void PasswordLineEdit::togglePasswordVisibility()
{
    if (password2Visible)
    {
        this->setEchoMode(QLineEdit::Password);
        eyeButton->setIcon(QIcon("assets/images/eye.png"));
        eyeButton->setToolTip("Show Password");
    }
    else
    {
        this->setEchoMode(QLineEdit::Normal);
        eyeButton->setIcon(QIcon("assets/images/eye2.png"));
        eyeButton->setToolTip("Hide Password");
    }

    password2Visible = !password2Visible;
}


void SignupPage::onLoginNowPress() {
	/* Here switchPage function changes the page 
	 * according to the assigned name
	 * (named assigned while doing addPage)
	 */
	app->switchPage("LoginPage");
}
