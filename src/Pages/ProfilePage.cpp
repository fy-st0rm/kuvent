
#include "ProfilePage.h"

void ProfilePage::onAttach() {
	v_profileLayout = new QVBoxLayout(this);
	setLayout(v_profileLayout);
	
	
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

	emailEntryLabel = new QLabel("");
	emailEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
	);
	hLayout3->addWidget(emailEntryLabel);
	hLayout3->setAlignment(Qt::AlignLeft);

	//line1
	QBoxLayout *hLayout4 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout4);

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
	
	QLabel *contactNoLabel = new QLabel("CONTACT NUMBER");
	contactNoLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
	);
	hLayout5->addWidget(contactNoLabel);
	hLayout5->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout6 = new QHBoxLayout();
	v_profileLayout->addLayout(hLayout6);

	contactNoEntryLabel = new EditableLabel([=]() {
		std::string number = contactNoEntryLabel->text().toStdString();
		changeProfileData("NUMBER", number);
	});
	contactNoEntryLabel->setText("");
	hLayout6->addWidget(contactNoEntryLabel);
	
	//line2
	QBoxLayout *hLayout7 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout7);

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

	facultyEntryLabel = new EditableLabel([=]() {
		std::string batch = facultyEntryLabel->text().toStdString();
		changeProfileData("BATCH", batch);
	});
	hLayout9->addWidget(facultyEntryLabel);

	//line4
	QBoxLayout *hLayout13 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout13);

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

	if (app_data.number == "NULL") {
		contactNoEntryLabel->setText("");
	}
	else {
		contactNoEntryLabel->setText(
			QString::fromStdString(app_data.number)
		);
	}

	if (app_data.batch == "NULL") {
		facultyEntryLabel->setText("");
	}
	else {
		facultyEntryLabel->setText(
			QString::fromStdString(app_data.batch)
		);
	}
}

void ProfilePage::changeProfileData(
	const std::string& attrib,
	const std::string& value
) {
	if (value.size() == 0)
		return;

	AppData app_data = app->getAppData();

	// Preparing payload
	Json::Value payload;
	payload["id"] = app_data.id;
	payload["attrib"] = attrib;
	payload[attrib] = value;

	Json::StyledWriter writer;
	std::string payload_str = writer.write(payload);

	// Sending the request to server
	httplib::Result res = app->client->Post(
		"/update_profile",
		payload_str,
		"application/json"
	);

	// Checking the response
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Update error",
			QString::fromStdString(res->body)
		);
		return;
	}
}

