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
	m_hLayout1 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout1);
	m_vLayout->addSpacing(1);
	m_vLayout->setAlignment(Qt::AlignVCenter);
	m_hLayout1->addWidget(m_Kuvent_logo);
	m_hLayout1->setAlignment(Qt::AlignHCenter);
	
	//username textbox styles
	email_label = new QLabel (this);
	email_entry = new EmailLineEdit(this);
	QPixmap userpng("assets/images/arroba.png");
	email_label->setPixmap(userpng);
	email_label->setScaledContents(true);
	email_label->setFixedSize(20,18);
	email_entry->setFixedSize(225,33.75);
	email_entry->setStyleSheet(
		"color: #000000;"
		"background-color:" + Theme::textboxBg +";"
		"border-radius:5px;"
		"padding: 5px;"
	);
	email_entry->setPlaceholderText("Email");
	applyShadow(email_entry);

	// horizontal layout for username
	m_hLayout2 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout2);
	m_vLayout->addSpacing(10);
	m_hLayout2->addWidget(email_label);
	m_hLayout2->addSpacing(10);
	m_hLayout2->addWidget(email_entry);
	m_hLayout2->setAlignment(Qt::AlignHCenter);

	// password textbox styles
	password_label = new QLabel(this);
	password_entry = new PasswordLineEdit(this);
	QPixmap passpng("assets/images/padlock.png");
	password_label->setPixmap(passpng);
	password_label->setScaledContents(true);
	password_label->setFixedSize(20,18);
	password_entry->setFixedSize(225,33.75);
	password_entry->setStyleSheet(
		"background-color:" + Theme::textboxBg +";"
		"color: #000000;"
		"border-radius: 5px;"
		"padding:5px;"
	);
	password_entry->setEchoMode(QLineEdit::Password);
	password_entry->setPlaceholderText("Password");
	applyShadow(password_entry);

	// another horizontal layout for password_label
	m_hLayout3 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout3);
	m_vLayout->addSpacing(10);
	m_hLayout3->addWidget(password_label);
	m_hLayout3->addSpacing(10);
	m_hLayout3->addWidget(password_entry);
	m_hLayout3->setAlignment(Qt::AlignHCenter);

	// login button styles
	m_login_button = new QPushButton("Login", this);
	m_login_button->setFixedSize(75,37.5);
	m_login_button->setStyleSheet(
        "QPushButton {"
            "background-color:" + Theme::buttonBg +";"
            "color: white;"
            "border-radius: 5px;"
			"font-family: Sans Serif;"
			"font-weight: bold;"
			"}"
        "QPushButton:hover {"
            "background-color:" + Theme::buttonHover +";"
        "}"
    );
	connect(
		m_login_button,
		&QPushButton::pressed,
		this,
		&LoginPage::onLoginButtonPress
	);
	applyShadow(m_login_button);

	//login button
	m_hLayout4 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout4);
	m_vLayout->setSpacing(10);
	m_hLayout4->addWidget(m_login_button);
	m_hLayout4->setAlignment(Qt::AlignHCenter);

	//dont have an account text styles
	m_notsigned = new QLabel("Don't have an account?", this);
	m_notsigned->setFixedSize(160,30);
	m_notsigned->setStyleSheet(
		"color:" + Theme::textwhite +";"
		"font-family: Sans Serif;"
		"font-weight: bold;"
		"font-size: 11px;"
		"letter-spacing: 1px;"
	);

	// create account button styles
	createaccount_button = new QLabel("<a href= \"SignupPage\" style = \"color: #09596D;" "text-decoration: none;"
										"font-style: italic; font-weight: bold\"> Create account </a>");
	createaccount_button->setFixedSize(100,30);
	connect(
		createaccount_button,
		&QLabel::linkActivated,
		this,
		&LoginPage::onCreateAccountPress
	);


	// create new account button
	m_hLayout5 = new QHBoxLayout();
	m_vLayout->addLayout(m_hLayout5);
	m_hLayout5->addSpacing(15);
	m_hLayout5->addWidget(m_notsigned);
	m_hLayout5->addSpacing(5);
	m_hLayout5->addWidget(createaccount_button);
	m_hLayout5->setAlignment(Qt::AlignHCenter);
}

	//Drop shadow effect
	void LoginPage::applyShadow(QWidget *widget) {
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
	shadow->setBlurRadius(4);
	shadow->setColor(QColor(Theme::dropshadow));
	
	// shadow->setOffset(QPointF(1, 1));
	if (qobject_cast<QLineEdit*>(widget)) 
		shadow->setOffset(QPointF(2, 2)); 
	else if (qobject_cast<QPushButton*>(widget)) 
		shadow->setOffset(QPointF(1, 1)); 
	
	widget->setGraphicsEffect(shadow);
}

void LoginPage::onLoginButtonPress() {
	QString email = email_entry->text();
	QString password = password_entry->text();
	QString requiredSuffixEmail = "@gmail.com";

	if (email.isEmpty() || password.isEmpty()) {
		QMessageBox::warning(this, "Login Error", "Please enter both username and password.");
		return;
	}
	else if (!email.endsWith("@gmail.com") || email.length() <= requiredSuffixEmail.length()) {
		QMessageBox::warning(this, "Login Error", "Please enter valid email.");
		return;
	}
	
	// Creating payload
	Json::Value payload;
	payload["email"] = email_entry->text().toStdString();
	payload["password"] = password_entry->text().toStdString();

	Json::StyledWriter writer;
	std::string payload_str = writer.write(payload);

	httplib::Result res = app->client->Post(
		"/login",
		payload_str,
		"application/json"
	);

	// Checking the response
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Login Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	// Abstracting response
	Json::Value res_data;
	Json::Reader reader;
	reader.parse(res->body, res_data);

	AppData app_data = {
		.id = res_data["id"].asString(),
		.username = res_data["username"].asString(),
		.email = res_data["email"].asString(),
		.number = res_data["number"].asInt(),
		.account_type = (AccountType) res_data["account_type"].asInt(),
		.batch = res_data["batch"].asString()
	};
	app->setAppData(app_data);

	app->switchPage("DashBoard");
}

void LoginPage::onCreateAccountPress(){
	app->switchPage("SignupPage");
}
