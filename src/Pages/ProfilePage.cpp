
#include "ProfilePage.h"

void ProfilePage::onAttach() {
	profileLayout = new QVBoxLayout(this);
	setLayout(profileLayout);
	
	//My Account label
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	profileLayout->addLayout(hLayout1);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *profileLabel = new QLabel("My Account");
	profileLabel->setStyleSheet(
			"font-size: 18pt;"
			"font-weight: bold;"
	);
	hLayout1->addWidget(profileLabel);
	hLayout1->setAlignment(Qt::AlignLeft);

	//Spacing left for profile pic
	profileLayout->addSpacing(159);	

	//Email label
	QBoxLayout *hLayout2 = new QHBoxLayout;
	profileLayout->addLayout(hLayout2);
	profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *emailLabel = new QLabel("EMAIL");
	emailLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout2->addWidget(emailLabel);
	hLayout2->setAlignment(Qt::AlignLeft);

	//email entry 
	QHBoxLayout *hLayout3 = new QHBoxLayout;
	profileLayout->addLayout(hLayout3);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *emailEntryLabel = new QLabel("kuvent@gmail.com");
	emailEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout3->addWidget(emailEntryLabel);
	hLayout3->setAlignment(Qt::AlignLeft);

	//line1
	QBoxLayout *hLayout4 = new QHBoxLayout;
	profileLayout->addLayout(hLayout4);
	profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::HLine); 
    line1->setFixedHeight(2);
	line1->setFixedWidth(this->width()/1.5);

	hLayout4->addWidget(line1); //Adding line to layout
	hLayout4->setAlignment(Qt::AlignLeft);

	profileLayout->addSpacing(10);

	//Contact Number Label
	QBoxLayout *hLayout5 = new QHBoxLayout;
	profileLayout->addLayout(hLayout5);
	profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *contactNoLabel = new QLabel("CONTACT NUMBER");
	contactNoLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout5->addWidget(contactNoLabel);
	hLayout5->setAlignment(Qt::AlignLeft);

	//Contact Number Entry
	QHBoxLayout *hLayout6 = new QHBoxLayout;
	profileLayout->addLayout(hLayout6);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *contactNoEntryLabel = new QLabel("9800000000");
	contactNoEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout6->addWidget(contactNoEntryLabel);
	hLayout6->setAlignment(Qt::AlignLeft);

	//line2
	QBoxLayout *hLayout7 = new QHBoxLayout;
	profileLayout->addLayout(hLayout7);
	profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::HLine); 
    line2->setFixedHeight(2);
	line2->setFixedWidth(this->width()/1.5);

	hLayout7->addWidget(line2); //Adding line to layout
	hLayout7->setAlignment(Qt::AlignLeft);

	profileLayout->addSpacing(10);

	//Program-Batch Label
	QBoxLayout *hLayout8 = new QHBoxLayout;
	profileLayout->addLayout(hLayout8);
	profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *programBatchLabel = new QLabel("PROGRAM-BATCH");
	programBatchLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout8->addWidget(programBatchLabel);
	hLayout8->setAlignment(Qt::AlignLeft);

	//Program-Batch Entry
	QHBoxLayout *hLayout9 = new QHBoxLayout;
	profileLayout->addLayout(hLayout9);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *programBatchEntryLabel = new QLabel("CE-2023");
	programBatchEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout9->addWidget(programBatchEntryLabel);
	hLayout9->setAlignment(Qt::AlignLeft);

	//line3
	QBoxLayout *hLayout10 = new QHBoxLayout;
	profileLayout->addLayout(hLayout10);
	profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line3 = new QFrame;
    line3->setFrameShape(QFrame::HLine); 
    line3->setFixedHeight(2);
	line3->setFixedWidth(this->width()/1.5);

	hLayout10->addWidget(line3); //Adding line to layout
	hLayout10->setAlignment(Qt::AlignLeft);

	profileLayout->addSpacing(40);

	//Password label
	QBoxLayout *hLayout11 = new QHBoxLayout;
	profileLayout->addLayout(hLayout11);
	profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *passwordLabel = new QLabel("Password");
	passwordLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout11->addWidget(passwordLabel);
	hLayout11->setAlignment(Qt::AlignLeft);

	//Password entry
	QHBoxLayout *hLayout12 = new QHBoxLayout;
	profileLayout->addLayout(hLayout12);
	profileLayout->setAlignment(Qt::AlignTop);

	QLabel *passwordEntryLabel = new QLabel("********");
	passwordEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout12->addWidget(passwordEntryLabel);
	hLayout12->setAlignment(Qt::AlignLeft);

	//line4
	QBoxLayout *hLayout13 = new QHBoxLayout;
	profileLayout->addLayout(hLayout13);
	profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line4 = new QFrame;
    line4->setFrameShape(QFrame::HLine); 
    line4->setFixedHeight(2);
	line4->setFixedWidth(this->width()/1.5);

	hLayout13->addWidget(line4); //Adding line to layout
	hLayout13->setAlignment(Qt::AlignLeft);

	profileLayout->addSpacing(10);

	//logout button
	QPushButton *logout_button = new QPushButton("Logout");
	logout_button->setStyleSheet(
			"color: red;"
			"background-color: white;"
	);
	logout_button->setMinimumSize(50,30);
	connect(
		logout_button,
		&QPushButton::clicked, this,
		[this]()
		{
			app->switchPage("LoginPage");
		}
			);

	QHBoxLayout *hLayout14 = new QHBoxLayout();
	profileLayout->addLayout(hLayout14);
	hLayout14->addWidget(logout_button, 0, Qt::AlignLeft);
}

