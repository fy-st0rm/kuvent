#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsDropShadowEffect>

#include "Application/Application.h"
#include "Application/Page.h"
#include "Widgets/PasswordLineEdit.h"

class SignupPage : public Page {
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();

private slots:
	void onLoginNowPress();
    void onSignupPress();

private:
	QVBoxLayout* m_main_layout;
	QLabel *create_account_title;
    QVBoxLayout *m_vLayout2;

    QLabel *username2;
    QLabel *password2;
    QLabel *email;
    QLabel *confirm_password2;
    QWidget *select_accounttype;
    QLabel *go_tologin;
    QPushButton *login_now;
    QLineEdit *add_username2;
    QLineEdit *add_email;
    QLineEdit *add_password2;
    QLineEdit *add_confirmpassword2;
    QComboBox *select_account_type;
    QLabel *account_type;
    QPushButton *signupButton;
    QLabel *errorLabel;

    void applyShadow(QWidget *widget);
};
