#include "Application/Application.h"
#include "SignupPage.h"
#include "theme.h"

void SignupPage::onAttach() {
    // Changing the stylesheet of the base widget of page
  getBaseWidget()->setStyleSheet("background-color:"+ Theme::PrimaryBg);

	// Creating main layout of this page
	m_vLayout2 = new QVBoxLayout;

	// Applying that main layout to the page
	setLayout(m_vLayout2);

    //Title text styles
    create_account_title = new QLabel("CREATE NEW ACCOUNT", this);
    create_account_title->setFixedSize(290, 50);
    create_account_title->setStyleSheet(
        "font-size: 16pt;"
        "font-family: Georgia, serif;"
        "color: #FFFFFF;"
        "font-weight: bold;"
        "letter-spacing: 1px;"
    );

    //Add username styles
  	username_label = new QLabel(this);
    username_entry = new QLineEdit(this);
    username_label->setFixedSize(20, 18);
    username_entry->setFixedSize(225,33.75);
    username_entry->setStyleSheet(
        "color: #000000;"
        "background-color:" + Theme::textboxBg +";"
        "border-radius: 5px;"
        "padding: 5px;"
        );
    username_entry->setPlaceholderText("Username");
    QPixmap userpng("assets/images/user.png");
    username_label->setPixmap(userpng);
    username_label->setScaledContents(true);
    applyShadow(username_entry);

    //Add email_label styles
    email_label = new QLabel(this);
    email_entry = new EmailLineEdit(this);
    email_label->setFixedSize(20, 18);
    QPixmap profilepng("assets/images/arroba.png");
    email_label->setPixmap(profilepng);
    email_label->setScaledContents(true);
    email_entry->setFixedSize(225,33.75);
    email_entry->setStyleSheet(
        "color: #000000;"
        "background-color:" + Theme::textboxBg +";" 
        "border-radius: 5px;"
        "padding: 5px;"
        );
    email_entry->setPlaceholderText("Email");
    applyShadow(email_entry);

    password_label = new QLabel(this);
    password_label->setFixedSize(20,18);
    QPixmap passpng("assets/images/padlock.png");
    password_label->setPixmap(passpng);
    password_label->setScaledContents(true);

    //Add password styles
    password_entry = new PasswordLineEdit(this);
    password_entry->setFixedSize(225,33.75);
    password_entry->setStyleSheet(
        "color: #000000;"
        "background-color:" + Theme::textboxBg +";"
        "border-radius: 5px;" 
        "padding: 5px;"
        );
    password_entry->setPlaceholderText("Password");
    applyShadow(password_entry);

    confirmPassword_label = new QLabel(this);
    confirmPassword_label->setFixedSize(20,18);
    QPixmap confirm_passpng("assets/images/reset-password.png");
    confirmPassword_label->setPixmap(confirm_passpng);
    confirmPassword_label->setScaledContents(true);

    //Add confirm password styles
    confirmPassword_entry = new PasswordLineEdit(this);
    confirmPassword_entry->setFixedSize(225,33.75);
    confirmPassword_entry->setStyleSheet(
        "color: #000000;"
        "background-color:" + Theme::textboxBg +";"
        "border-radius: 5px;" 
        "padding: 5px;"
        );
    confirmPassword_entry->setPlaceholderText("Confirm Password");
    applyShadow(confirmPassword_entry);

    //Account type text styles
    account_type = new QLabel("Account Type : ", this);
    account_type->setFixedSize(100,30);
    account_type->setStyleSheet(
		"color:" + Theme::textwhite +";"
		"font-family: Sans Serif;"
		"font-weight: bold;"
		"font-size: 11px;"
		"letter-spacing: 1px;"
	);

    //Select account type dropdown styles
    select_account_type = new QComboBox(this);
    select_account_type->setFixedSize(100,25);
    select_account_type->setStyleSheet(
        "color: #000000;"
        "background-color: #FAF6E7;" 
        "border-radius:5px;"
        "padding: 5px;"													
        );
    select_account_type->addItem("Participant");
    select_account_type->addItem("Organizer");
    applyShadow(select_account_type);

    //Signup button styles
    signup_Button = new QPushButton("Signup", this);
    signup_Button->setFixedSize(75,37.5);
    signup_Button->setStyleSheet(
        "QPushButton {"
            "background-color:" + Theme::buttonBg +";"
            "color: white;"
            "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
            "background-color:" + Theme::buttonHover +";"
        "}"
    );
    applyShadow(signup_Button);
		connect(
			signup_Button,
			&QPushButton::pressed,
			this,
			&SignupPage::onSignupPress
		);

    //Already have an account text styles
    goLogin_button = new QLabel("Already have an account?", this);
    goLogin_button->setStyleSheet(
		"color:" + Theme::textwhite +";"
		"font-family: Sans Serif;"
		"font-weight: bold;"
		"font-size: 11px;"
		"letter-spacing: 1px;"
	);
    goLogin_button->setFixedSize(170,30);

    loginnow_button = new QLabel(
        "<a"
        " href= \"LoginPage\""
        " style = \""
        "  color: #09596D;"
        "  text-decoration: none;"
        "  font-style: italic;" 
        "  font-weight: bold;"
        "\"> Login now </a>"
    );
    loginnow_button->setFixedSize(75,37.5);
    loginnow_button->setStyleSheet(
        "padding: 5px;"
        
    );
		connect(
			loginnow_button,
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
    m_hLayout7->addWidget(username_label);
    m_hLayout7->addSpacing(10);
    m_hLayout7->addWidget(username_entry);
    m_vLayout2->addLayout(m_hLayout7);
    m_hLayout7->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout8 = new QHBoxLayout();
    m_hLayout8->addWidget(email_label);
    m_hLayout8->addSpacing(10);
    m_hLayout8->addWidget(email_entry);
    m_vLayout2->addLayout(m_hLayout8);
    m_hLayout8->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout9 = new QHBoxLayout();
    m_hLayout9->addWidget(password_label);
    m_hLayout9->addSpacing(10);
    m_hLayout9->addWidget(password_entry);
    m_vLayout2->addLayout(m_hLayout9);
    m_hLayout9->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout10 = new QHBoxLayout();
    m_hLayout10->addWidget(confirmPassword_label);
    m_hLayout10->addSpacing(10);
    m_hLayout10->addWidget(confirmPassword_entry);
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
    m_hLayout12->addWidget(signup_Button);
    m_vLayout2->addLayout(m_hLayout12);
    m_hLayout12->setAlignment(Qt::AlignHCenter);
    m_vLayout2->addSpacing(10);

    QHBoxLayout *m_hLayout13 = new QHBoxLayout();
    m_hLayout13->addWidget(goLogin_button);
    m_hLayout13->addSpacing(1);
    m_hLayout13->addWidget(loginnow_button);
    m_vLayout2->addLayout(m_hLayout13);
    m_hLayout13->setAlignment(Qt::AlignHCenter);
    m_vLayout2->setSpacing(10);


}

void SignupPage::applyShadow(QWidget *widget)
{
    //drop shadow styles
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
	shadow->setBlurRadius(5);
	shadow->setColor(QColor(Theme::dropshadow));
	// shadow->setOffset(QPointF(1, 1));
	if (qobject_cast<QLineEdit*>(widget)) 
		shadow->setOffset(QPointF(2, 2)); 
	else if (qobject_cast<QPushButton*>(widget)) 
		shadow->setOffset(QPointF(1, 1));
    else if (qobject_cast<QComboBox*>(widget)) 
		shadow->setOffset(QPointF(1, 1));  
	
	widget->setGraphicsEffect(shadow);
}

void SignupPage::onSignupPress() {

    QString name = username_entry->text();
    QString email = email_entry->text();
    QString password = password_entry->text();
    QString confirm_password = confirmPassword_entry->text();

    if (name.isEmpty() || email.isEmpty() || password.isEmpty() || confirm_password.isEmpty())
    {
        QMessageBox::warning(this, "Signup Error", "Please enter all the details.");
        return;
    }

    else if (password != confirm_password)
    {
        QMessageBox::warning(this, "Signup Error", "Passwords do not match.");
    }

    else if(!email.endsWith("@gmail.com"))
	{
		QMessageBox::warning(this, "Login Error", "Please enter valid email.");
	}
    
    else {
        //Connecting to the server
        httplib::Client cli("localhost", 8080);

        std::stringstream payload;
        payload << "{";
        payload << "\"username\": \"" << username_entry->text().toStdString() << "\",";
        payload << "\"email\": \"" << email_entry->text().toStdString() << "\",";
        payload << "\"password\": \"" << password_entry->text().toStdString() << "\",";
        payload << "\"type\": \"" << select_account_type->currentText().toStdString() << "\"";
        payload << "}";



        httplib::Result res = cli.Post(
            "/signup",
            payload.str(),
            "application/json"
        );

        if (res->status != httplib::StatusCode::OK_200) {
            QMessageBox::information(
                this,
                "Signup Error",
                QString::fromStdString(res->body)
            );
            return;
        }

        QMessageBox::information(
            this,
            "Signup Sucess",
            QString::fromStdString(res->body)
        );

        app->switchPage("LoginPage");
    }
}

void SignupPage::onLoginNowPress() {
	/* Here switchPage function changes the page 
	 * according to the assigned name
	 * (named assigned while doing addPage)
	 */
	app->switchPage("LoginPage");
}
