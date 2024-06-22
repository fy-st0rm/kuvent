#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("KUvents");
    MainWindow w;
    w.setWindowTitle(a.applicationName());
    w.show();
    return a.exec();
}
