#include "dashBoardNavBar.h"
#include "theme.h"
#include <QtGui/QIcon>

DashBoardNavBar::DashBoardNavBar(QWidget *parent)
	: QVBoxLayout(parent)
{
	this->setSpacing(20);
	this->setContentsMargins(0, 20, 0, 20);
	this->addStretch();

	createButton(profile_button, "assets/images/user.png");
	createButton(ongoing_button, "assets/images/ongoing.png");
	createButton(upcoming_button, "assets/images/upcoming.png");
	createButton(post_button, "assets/images/plus.png");

	profile_button->setToolTip("Profile");
	ongoing_button->setToolTip("Ongoing Events");
	upcoming_button->setToolTip("Upcoming Events");
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
}

void DashBoardNavBar::createButton(QPushButton *&button,const QString &iconPath) {
	button = new QPushButton;
	button->setIcon(QIcon(iconPath));
	button->setIconSize(QSize(40, 30));
	button->setFixedSize(50, 50);
	button->setStyleSheet(
		"QToolTip {"
		"background-color: white;"
		"}"
		"QToolTip:hover {"
		"background-color: white;"
		"}"
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
}

void DashBoardNavBar::onEntry(AccountType account_type) {
	this->insertWidget(this->count() - 1, profile_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	this->insertWidget(this->count() - 1, ongoing_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	this->insertWidget(this->count() - 1, upcoming_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	resetButtonStyles();
	profile_button->setStyleSheet(
		"background-color:" + Theme::dashboardhoverBg + ";"
		"border-radius: 15px;" 
	);

	if (account_type == ORGANIZER) {
		this->insertWidget(this->count() - 1, post_button, 0, Qt::AlignHCenter | Qt::AlignTop);
		post_button->show();
	}
}

void DashBoardNavBar::onExit(AccountType account_type) {
	this->removeWidget(profile_button);
	this->removeWidget(ongoing_button);
	this->removeWidget(upcoming_button);

	if (account_type == ORGANIZER) {
		std::cout << "REMOVING\n";
		this->removeWidget(post_button);
		post_button->hide();
	}
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
		"QToolTip {"
		"background-color: white;"
		"}"
		"QToolTip:hover {"
		"background-color: white;"
		"}"
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
	);
	ongoing_button->setStyleSheet(
		"QToolTip {"
		"background-color: white;"
		"}"
		"QToolTip:hover {"
		"background-color: white;"
		"}"
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
	);
	upcoming_button->setStyleSheet(
		"QToolTip {"
		"background-color: white;"
		"}"
		"QToolTipk:hover {"
		"background-color: white;"
		"}"
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
	);
	post_button->setStyleSheet(
		"QToolTip {"
		"background-color: white;"
		"}"
		"QToolTip:hover {"
		"background-color: white;"
		"}"
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
	);
}
