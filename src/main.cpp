#include "loginWindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("KUvent");
    LoginWindow lw;
    lw.setWindowTitle(app.applicationName());
    lw.show();
    return app.exec();
}