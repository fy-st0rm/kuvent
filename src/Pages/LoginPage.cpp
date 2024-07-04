#include "LoginPage.h"
#include "theme.h"

void LoginPage::onAttach() {
	// Changing the stylesheet of the base widget of page
	getBaseWidget()->setStyleSheet("background-color:" + Theme::PrimaryBg); 

	// m_vLayout is the main layout of the page
	m_vLayout = new QVBoxLayout();

	// IMP: Do not forget to set the layout of the page to the main layout
	setLayout(m_vLayout);

	// Here goes the login widget codes...

	// Kuvent logo
	m_Kuvent_logo = new QLabel(this);
	QPixmap loginlogo("assets/images/KUventpng.png");
	m_Kuvent_logo->setPixmap(loginlogo);
	m_Kuvent_logo->setFixedSize(400,180);
	m_Kuvent_logo->setScaledContents(true);
 
	//horizontal layout for m_Kuvent_logo
	QHBoxLayout *m_hLayout1 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout1);
	m_vLayout->addSpacing(1);
	m_vLayout->setAlignment(Qt::AlignVCenter);
	m_hLayout1->addWidget(m_Kuvent_logo);
	m_hLayout1->setAlignment(Qt::AlignHCenter);
	
	//username textbox styles
	m_username = new QLabel (this);
	m_add_username = new QLineEdit(this);
	QPixmap userpng("assets/images/arroba.png");
	m_username->setPixmap(userpng);
	m_username->setScaledContents(true);
	m_username->setFixedSize(20,18);
	m_add_username->setFixedSize(225,33.75);
	m_add_username->setStyleSheet(
		"color: #000000;"
		"background-color: #FAF6E7;"
		"border-radius:5px;"
		"padding: 5px;"
	);
	m_add_username->setPlaceholderText("Username");
	applyShadow(m_add_username);

	// horizontal layout for username
	QHBoxLayout *m_hLayout2 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout2);
	m_vLayout->addSpacing(10);
	m_hLayout2->addWidget(m_username);
	m_hLayout2->addSpacing(10);
	m_hLayout2->addWidget(m_add_username);
	m_hLayout2->setAlignment(Qt::AlignHCenter);

	// password textbox styles
	m_password = new QLabel(this);
	m_add_password = new PasswordLineEdit(this);
	QPixmap passpng("assets/images/padlock.png");
	m_password->setPixmap(passpng);
	m_password->setScaledContents(true);
	m_password->setFixedSize(20,18);
	m_add_password->setFixedSize(225,33.75);
	m_add_password->setStyleSheet(
		"background-color: #FAF6E7;"
		"color: #000000;"
		"border-radius: 5px;"
		"padding:5px;"
	);
	m_add_password->setEchoMode(QLineEdit::Password);
	m_add_password->setPlaceholderText("Password");
	applyShadow(m_add_password);

	// another horizontal layout for m_password
	QHBoxLayout *m_hLayout3 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout3);
	m_vLayout->addSpacing(10);
	m_hLayout3->addWidget(m_password);
	m_hLayout3->addSpacing(10);
	m_hLayout3->addWidget(m_add_password);
	m_hLayout3->setAlignment(Qt::AlignHCenter);

	// login button styles
	m_login_button = new QPushButton("Login", this);
	m_login_button->setFixedSize(75,37.5);
	m_login_button->setStyleSheet(
								"background-color: #7469B6;"
								 "color: white;"
								 "border-radius: 6px;");
	connect(
		m_login_button,
		&QPushButton::pressed,
		this,
		&LoginPage::onLoginButtonPress
	);
	applyShadow(m_login_button);

	//login button
	QHBoxLayout *m_hLayout4 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout4);
	m_vLayout->setSpacing(10);
	m_hLayout4->addWidget(m_login_button);
	m_hLayout4->setAlignment(Qt::AlignHCenter);

	//create account label styles
	m_notsigned = new QLabel("Don't have an account?", this);
	m_notsigned->setFixedSize(125,30);
	m_createaccount_button = new QLabel("<a href= \"SignupPage\" style = \"color: black; text-decoration: none;"
										"font-style: italic; font-weight: bold\"> Create account </a>");
	m_createaccount_button->setFixedSize(100,30);
	connect(
		m_createaccount_button,
		&QLabel::linkActivated,
		this,
		&LoginPage::onCreateAccountPress
	);

	// create new account button
	QHBoxLayout *m_hLayout5 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout5);
	m_hLayout5->addSpacing(15);
	m_hLayout5->addWidget(m_notsigned);
	m_hLayout5->addSpacing(5);
	m_hLayout5->addWidget(m_createaccount_button);
	m_hLayout5->setAlignment(Qt::AlignHCenter);
}

	//Drop shadow effect
void LoginPage::applyShadow(QWidget *widget) {
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
	shadow->setBlurRadius(4);
	shadow->setColor(QColor("#758694"));
	
	// shadow->setOffset(QPointF(1, 1));
	if (qobject_cast<QLineEdit*>(widget)) 
		shadow->setOffset(QPointF(2, 2)); 
	else if (qobject_cast<QPushButton*>(widget)) 
		shadow->setOffset(QPointF(1, 1)); 
	
	widget->setGraphicsEffect(shadow);
}

void LoginPage::onLoginButtonPress() {
	QString name = m_add_username->text();
	QString password = m_add_password->text();

	if (name.isEmpty() || password.isEmpty()) {
		QMessageBox::information(this, "Login Error", "Please enter both username and password.");
		return;
	}

	// Connecting to the server
	httplib::Client cli("localhost", 8080);

	std::stringstream payload;
	payload << "{";
	payload << "\"email\": \"" << m_add_username->text().toStdString() << "\",";
	payload << "\"password\": \"" << m_add_password->text().toStdString() << "\"";
	payload << "}";

	httplib::Result res = cli.Post(
		"/login",
		payload.str(),
		"application/json"
	);
	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::information(
			this,
			"Login Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	app->switchPage("DashBoard");
}

void LoginPage::onCreateAccountPress(){
	app->switchPage("SignupPage");
}
