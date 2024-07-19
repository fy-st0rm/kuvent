#include "dashBoardNavBar.h"
#include "theme.h"
#include <QtGui/QIcon>'

DashBoardNavBar::DashBoardNavBar(bool isOrganizer,QString user_name,QWidget *parent)
    : QVBoxLayout(parent)
{
    this->setSpacing(20);
    this->setContentsMargins(0, 20, 0, 20);

    createButton(profile_button, "assets/images/user.png");
    createButton(ongoing_button, "assets/images/ongoing.png");
    createButton(upcoming_button, "assets/images/upcoming.png");
    if (isOrganizer)
        createButton(post_button, "assets/images/plus.png");

    profile_button->setToolTip("Profile");
    ongoing_button->setToolTip("Ongoing Events");
    upcoming_button->setToolTip("Upcoming Events");
    if(isOrganizer)
        post_button->setToolTip("Post");

    connect(profile_button, &QPushButton::clicked, [=] () {
        resetButtonStyles();
        profile_button->setStyleSheet(
           "background-color:" + Theme::dashboardhoverBg + ";"
            "border-radius: 15px;" 
        );
    });

    connect(ongoing_button, &QPushButton::clicked, [=] () {
        resetButtonStyles();
        ongoing_button->setStyleSheet(
           "background-color:" + Theme::dashboardhoverBg + ";"
            "border-radius: 15px;" 
        );
    });

    connect(upcoming_button, &QPushButton::clicked, [=] () {
        resetButtonStyles();
        upcoming_button->setStyleSheet(
           "background-color:" + Theme::dashboardhoverBg + ";"
            "border-radius: 15px;" 
        );
    });

    connect(post_button, &QPushButton::clicked, [=] () {
        resetButtonStyles();
        post_button->setStyleSheet(
           "background-color:" + Theme::dashboardhoverBg + ";"
            "border-radius: 15px;" 
        );
    });
    
    this->addStretch();
}

void DashBoardNavBar::createButton(QPushButton *&button,const QString &iconPath)
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

QPushButton *DashBoardNavBar::getProfileButton()
{
    return profile_button;
}

QPushButton *DashBoardNavBar::getOngoingButton()
{
    return ongoing_button;
}

QPushButton *DashBoardNavBar::getUpcomingButton()
{
    return upcoming_button;
}

QPushButton *DashBoardNavBar::getPostButton()
{
    return post_button;
}

void DashBoardNavBar::resetButtonStyles()
{
    profile_button->setStyleSheet(
        "border-radius: 25px;"
        "border: 2px;"
        "background-color:" + Theme::dashboardBg + ";"
    );
    ongoing_button->setStyleSheet(
        "border-radius: 25px;"
        "border: 2px;"
        "background-color:" + Theme::dashboardBg + ";"
    );
    upcoming_button->setStyleSheet(
        "border-radius: 25px;"
        "border: 2px;"
        "background-color:" + Theme::dashboardBg + ";"
    );
    post_button->setStyleSheet(
        "border-radius: 25px;"
        "border: 2px;"
        "background-color:" + Theme::dashboardBg + ";"
    );
}