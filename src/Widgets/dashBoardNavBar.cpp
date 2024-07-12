#include "dashBoardNavBar.h"
#include "theme.h"
#include <QtGui/QIcon>

DashBoardNavBar::DashBoardNavBar(QWidget *parent)
    : QVBoxLayout(parent)
{
    this->setSpacing(20);
    this->setContentsMargins(0, 20, 0, 20);

    createButton(profile_button, "assets/images/user.png");
    createButton(ongoing_button, "assets/images/ongoing.png");
    createButton(upcoming_button, "assets/images/upcoming.png");
    createButton(post_button, "assets/images/plus.png");

    this->addStretch();
}

void DashBoardNavBar::createButton(QPushButton *&button, const QString &iconPath)
{
    button = new QPushButton(parentWidget());
    button->setIcon(QIcon(iconPath));
    button->setIconSize(QSize(40, 30));
    button->setFixedSize(50, 50);
    button->setStyleSheet(
        "QPushButton {"
        "border-radius: 25px;"
        "border: 2px;"
        "background-color:" + Theme::dashboardBg + ";"
        "}"
        "QPushButton:hover {"
        "background-color:" + Theme::dashboardhoverBg + ";"
        "border-radius: 15px;"
        "}"
    );
    this->addWidget(button, 0, Qt::AlignHCenter | Qt::AlignTop);
}