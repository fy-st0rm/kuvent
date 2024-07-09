#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QToolButton>
#include <QtGui/QFont>

#include <sstream>

#include "httplib.h"
#include "json/json.h"
#include "Application/Application.h"
#include "Application/Page.h"
#include "Widgets/PasswordLineEdit.h"

class LoginPage : public Page {
public:
	void onAttach();

private slots: 
	void onLoginButtonPress();
	void onCreateAccountPress();

private:
	QPushButton *m_login_button;
	QLabel *email_label;
	QVBoxLayout *m_vLayout;
	QHBoxLayout *m_hLayout1;
	QHBoxLayout *m_hLayout2;
	QHBoxLayout *m_hLayout3;
	QHBoxLayout *m_hLayout4;
	QHBoxLayout *m_hLayout5;
	QLabel *m_notsigned;

	QLineEdit *email_entry;
	QLabel *password_label;
	QLineEdit *password_entry;
	QLabel *m_Kuvent_logo;
	QLabel *createaccount_button;

	void applyShadow(QWidget *widget);
};
