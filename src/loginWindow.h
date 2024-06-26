#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "ui_loginWindow.h"
#include <QtCore/QSize>
#include <QtCore/QDebug>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QSize>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}

QT_END_NAMESPACE
class LoginWindow : public QMainWindow
{
public:
    LoginWindow(QWidget *parent = nullptr);
    void onLoginButtonPress();
    void onCreateAccountPress();

    ~LoginWindow();


private:
    Ui::LoginWindow *m_ui;
    QPushButton *m_login_button;
    QLabel *m_username;
    QVBoxLayout *m_vLayout;
    QHBoxLayout *m_hLayout1;
    QHBoxLayout *m_hLayout2;
    QHBoxLayout *m_hLayout3;
    QHBoxLayout *m_hLayout4;
    QHBoxLayout *m_hLayout5;
    QLabel *m_notsigned;

    QWidget *centralWidget;
    QLineEdit *m_add_username;
    QLabel *m_password;
    QLineEdit *m_add_password;
    QLabel *m_Kuvent_logo;
    QPushButton *m_createaccount_button;

    void applyShadow(QLineEdit *lineEdit);
    void applyShadow(QPushButton *pushButton);


    
};
#endif // LOGINWINDOW_H
