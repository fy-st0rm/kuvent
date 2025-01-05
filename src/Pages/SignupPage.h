#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QGraphicsDropShadowEffect>

#include <sstream>

#include "httplib.h"
#include "json/json.h"
#include "Application/Application.h"
#include "Application/Page.h"
#include "Widgets/PasswordLineEdit.h"
#include "Widgets/emailValidation.h"
#include "utils.h"

class SignupPage : public Page {
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();
	void onEntry() {}

private:
	void onLoginNowPress();
    void onSignupPress();

private:
	QVBoxLayout* m_main_layout;
	QLabel *create_account_title;
	QVBoxLayout *m_vLayout2;

	QLabel *username_label;
	QLabel *password_label;
	QLabel *email_label;
	QLabel *confirmPassword_label;
	QWidget *select_accounttype;
	QLabel *goLogin_button;
	QLabel *loginnow_button;
	QLineEdit *username_entry;
	QLineEdit *email_entry;
	QLineEdit *password_entry;
	QLineEdit *confirmPassword_entry;
	QComboBox *select_account_type;
	QLabel *account_type;
	QPushButton *signup_Button;
};
