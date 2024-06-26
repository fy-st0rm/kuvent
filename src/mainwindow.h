#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
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
class MainWindow;
}

QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
    void onLoginButtonPress();
    void onCreateAccountPress();

    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QPushButton *login_button;
    QLabel *username;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout1;
    QHBoxLayout *hLayout2;
    QHBoxLayout *hLayout3;
    QHBoxLayout *hLayout4;
    QHBoxLayout *hLayout5;
    QLabel *notsigned;

    QWidget *centralWidget;
    QLineEdit *add_username;
    QLabel *password;
    QLineEdit *add_password;
    QLabel *logo;
    QPushButton *createaccount_button;

    void applyShadow(QLineEdit *lineEdit);
    void applyShadow(QPushButton *pushButton);


    
};
#endif // MAINWINDOW_H
