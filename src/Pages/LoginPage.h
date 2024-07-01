#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QToolButton>

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
	QLabel *m_username;
	QVBoxLayout *m_vLayout;
	QHBoxLayout *m_hLayout1;
	QHBoxLayout *m_hLayout2;
	QHBoxLayout *m_hLayout3;
	QHBoxLayout *m_hLayout4;
	QHBoxLayout *m_hLayout5;
	QLabel *m_notsigned;

	QLineEdit *m_add_username;
	QLabel *m_password;
	QLineEdit *m_add_password;
	QLabel *m_Kuvent_logo;
	QPushButton *m_createaccount_button;

	void applyShadow(QWidget *widget);
};
