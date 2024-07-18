
#include "ProfilePage.h"

void ProfilePage::onAttach() {
	profileLayout = new QVBoxLayout(this);
	setLayout(profileLayout);
	
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	profileLayout->addLayout(hLayout1);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *profileLabel = new QLabel("Profile Page");
	profileLabel->setStyleSheet("font-size: 16pt;");
	hLayout1->addWidget(profileLabel);
	hLayout1->setAlignment(Qt::AlignHCenter);

	profileLayout->addSpacing(10);

	QPushButton *logout_button = new QPushButton("Logout");
	logout_button->setStyleSheet(
			"color: red;"
			"background-color: white;"
	);
	logout_button->setMinimumSize(50,30);
	connect(
		logout_button,
		&QPushButton::clicked, this,
		[this]() {
			app->switchPage("LoginPage");
	});

	QHBoxLayout *hLayout2 = new QHBoxLayout();
	profileLayout->addLayout(hLayout2);
	hLayout2->addWidget(logout_button, 0, Qt::AlignHCenter);
}

