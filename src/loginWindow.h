#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "ui_loginWindow.h"
#include <QtWidgets/QLabel>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
// #include <QtGui/QPixmap>
// #include <QtWidgets/QCommandLinkButton>
// #include <QtWidgets/QMainWindow>
// #include <QtCore/QDebug>
// #include <QtCore/QSize>

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

    void applyShadow(QWidget *widget);



    
};
#endif // LOGINWINDOW_H
