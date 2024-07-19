
#include "ProfilePage.h"

void ProfilePage::onAttach() {
	v_profileLayout = new QVBoxLayout(this);
	setLayout(v_profileLayout);
	h_profileLayout = new QHBoxLayout(this);
	setLayout(h_profileLayout);
	
	
	//My Account label
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout1);
	v_profileLayout->setAlignment(Qt::AlignTop);

	profileLabel = new QLabel("My Account");
	profileLabel->setStyleSheet(
			"font-size: 18pt;"
			"font-weight: bold;"
	);
	hLayout1->addWidget(profileLabel);
	hLayout1->setAlignment(Qt::AlignLeft);

	//Spacing left for profile pic
	v_profileLayout->addSpacing(15);	

	//Profile Picture
	QBoxLayout *hLayout15 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout15);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QLabel *profilePic = new QLabel(this);
	QPixmap profile("assets/images/KUventpp.png");
	profilePic->setPixmap(profile);
	profilePic->setFixedSize(100,100);
	profilePic->setScaledContents(true);
	hLayout15->addWidget(profilePic);
	hLayout15->setAlignment(Qt::AlignLeft);

	//line5
	QFrame *line5 = new QFrame;
    line5->setFrameShape(QFrame::HLine); 
    line5->setFixedHeight(2);
	line5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	hLayout15->addWidget(line5); //Adding line to layout

	v_profileLayout->addSpacing(40);

	//Email label
	QBoxLayout *hLayout2 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout2);
	v_profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *emailLabel = new QLabel("EMAIL");
	emailLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout2->addWidget(emailLabel);
	hLayout2->setAlignment(Qt::AlignLeft);

	//email entry 
	QHBoxLayout *hLayout3 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout3);
	v_profileLayout->setAlignment(Qt::AlignTop);

	emailEntryLabel = new QLabel("kuvent@gmail.com");
	emailEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout3->addWidget(emailEntryLabel);
	hLayout3->setAlignment(Qt::AlignLeft);

	//line1
	QBoxLayout *hLayout4 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout4);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::HLine); 
    line1->setFixedHeight(2);
	line1->setFixedWidth(this->width()/1.5);

	hLayout4->addWidget(line1); //Adding line to layout
	hLayout4->setAlignment(Qt::AlignLeft);

	v_profileLayout->addSpacing(10);

	//Contact Number Label
	QBoxLayout *hLayout5 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout5);
	v_profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *contactNoLabel = new QLabel("CONTACT NUMBER");
	contactNoLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout5->addWidget(contactNoLabel);
	hLayout5->setAlignment(Qt::AlignLeft);

	//Contact Number Entry
	QHBoxLayout *hLayout6 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout6);
	v_profileLayout->setAlignment(Qt::AlignTop);

	contactNoEntryLabel = new QLabel("9800000000");
	contactNoEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout6->addWidget(contactNoEntryLabel);
	hLayout6->setAlignment(Qt::AlignLeft);

	//to add space between contact number and edit button
	QSpacerItem *spacer = new QSpacerItem(225, 10);
	hLayout6->addItem(spacer);

	//edit button for contact number
	QPushButton *edit_contact_button = new QPushButton("Edit");
	edit_contact_button->setStyleSheet(
			"color: red;"
			"background-color: white;"
	);
	edit_contact_button->setMinimumSize(50,30);
	h_profileLayout->addLayout(hLayout6);
	hLayout6->addWidget(edit_contact_button, 0, Qt::AlignRight);

	//line2
	QBoxLayout *hLayout7 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout7);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::HLine); 
    line2->setFixedHeight(2);
	line2->setFixedWidth(this->width()/1.5);

	hLayout7->addWidget(line2); //Adding line to layout
	hLayout7->setAlignment(Qt::AlignLeft);

	v_profileLayout->addSpacing(10);

	//Program-Batch Label
	QBoxLayout *hLayout8 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout8);
	v_profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *programBatchLabel = new QLabel("PROGRAM-BATCH");
	programBatchLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout8->addWidget(programBatchLabel);
	hLayout8->setAlignment(Qt::AlignLeft);

	//Program-Batch Entry
	QHBoxLayout *hLayout9 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout9);
	v_profileLayout->setAlignment(Qt::AlignTop);

	programBatchEntryLabel = new QLabel("CE-2023");
	programBatchEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout9->addWidget(programBatchEntryLabel);
	hLayout9->setAlignment(Qt::AlignLeft);

	//to add space between program-batch and edit button
	QSpacerItem *spacer2 = new QSpacerItem(252, 10);
	hLayout9->addItem(spacer2);

	//edit button for program-batch
	QPushButton *edit_programBatch_button = new QPushButton("Edit");
	edit_programBatch_button->setStyleSheet(
			"color: red;"
			"background-color: white;"
	);
	edit_programBatch_button->setMinimumSize(50,30);
	v_profileLayout->addLayout(hLayout9);
	hLayout9->addWidget(edit_programBatch_button, 0, Qt::AlignRight);

	//line3
	QBoxLayout *hLayout10 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout10);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line3 = new QFrame;
    line3->setFrameShape(QFrame::HLine); 
    line3->setFixedHeight(2);
	line3->setFixedWidth(this->width()/1.5);

	hLayout10->addWidget(line3); //Adding line to layout
	hLayout10->setAlignment(Qt::AlignLeft);

	v_profileLayout->addSpacing(35);

	//Password label
	QBoxLayout *hLayout11 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout11);
	v_profileLayout->setAlignment(Qt::AlignTop);
	
	QLabel *passwordLabel = new QLabel("Password");
	passwordLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout11->addWidget(passwordLabel);
	hLayout11->setAlignment(Qt::AlignLeft);

	//Password entry
	QHBoxLayout *hLayout12 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout12);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QLabel *passwordEntryLabel = new QLabel("********");
	passwordEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout12->addWidget(passwordEntryLabel);
	hLayout12->setAlignment(Qt::AlignLeft);

	//to add space between program-batch and edit button
	QSpacerItem *spacer3 = new QSpacerItem(230, 10);
	hLayout12->addItem(spacer3);

	//edit button for contact number
	QPushButton *change_password_button = new QPushButton("Change Password");
	change_password_button->setStyleSheet(
			"color: red;"
			"background-color: white;"
	);
	change_password_button->setMinimumSize(100,30);
	v_profileLayout->addLayout(hLayout12);
	hLayout12->addWidget(change_password_button, 0, Qt::AlignRight);

	//line4
	QBoxLayout *hLayout13 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout13);
	v_profileLayout->setAlignment(Qt::AlignTop);

	QFrame *line4 = new QFrame;
    line4->setFrameShape(QFrame::HLine); 
    line4->setFixedHeight(2);
	line4->setFixedWidth(this->width()/1.5);

	hLayout13->addWidget(line4); //Adding line to layout
	hLayout13->setAlignment(Qt::AlignLeft);

	v_profileLayout->addSpacing(25);

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
	v_profileLayout->addLayout(hLayout14);
	hLayout14->addWidget(logout_button, 0, Qt::AlignLeft);
}

void ProfilePage::onEntry() {
	AppData app_data = app->getAppData();

	emailEntryLabel->setText(
		QString::fromStdString(app_data.email)
	);

	if (app_data.number == 0) {
		contactNoEntryLabel->setText("");
	}
	else {
		contactNoEntryLabel->setText(
			QString::number(app_data.number)
		);
	}
	programBatchEntryLabel->setText(
		QString::fromStdString(app_data.batch)
	);
}

