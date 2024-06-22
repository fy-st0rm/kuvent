#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QSize>

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
    QPushButton *button1;
    QLabel *username;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QHBoxLayout *hLayout1;
    QHBoxLayout *hLayout2;
    QWidget *centralWidget;
    QLineEdit *add;
    QLabel *password;
    QLineEdit *addpassword;
};
#endif // MAINWINDOW_H
