#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QSize>
#include <QtWidgets/QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *login_button;
    QPushButton *signup_button;
    QLabel *username;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout1;
    QHBoxLayout *hLayout2;
    QHBoxLayout *hLayout3;
    QHBoxLayout *hLayout4;
    // QHBoxLayout *hLayout5;

    QWidget *centralWidget;
    QLineEdit *add_username;
    QLabel *password;
    QLineEdit *add_password;
    QLabel *logo;

    void applyShadow(QLineEdit *lineEdit);
    
};
#endif // MAINWINDOW_H
