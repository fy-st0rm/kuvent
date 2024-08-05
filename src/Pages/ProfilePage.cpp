
#include "ProfilePage.h"
#include "theme.h"

void ProfilePage::onAttach() {
	v_profileLayout = new QVBoxLayout(this);
	setLayout(v_profileLayout);

	// App Data
	app_data = app->getAppData();
	
	//My Account label
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout1);
	v_profileLayout->setAlignment(Qt::AlignTop);

	profileLabel = new QLabel("My Account");
	profileLabel->setStyleSheet(
			"font-size: 18pt;"
			"font-weight: bold;"
			"color: #000000;"
	);
	hLayout1->addWidget(profileLabel);
	hLayout1->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout0 = new QHBoxLayout();
	v_profileLayout->addLayout(hLayout0);

	//Horizontal line
	QFrame *line0 = new QFrame;
    line0->setFrameShape(QFrame::HLine); 
    line0->setFixedHeight(2);
	line0->setFixedWidth(this->width()/1.5);
	line0->setStyleSheet("color: #000000;");

	hLayout0->addWidget(line0); //Adding line to layout
	hLayout0->setAlignment(Qt::AlignBottom);

	v_profileLayout->addSpacing(10);	

	// Profile Picture
    QHBoxLayout *hLayout15 = new QHBoxLayout;
    v_profileLayout->addLayout(hLayout15);

    LabelWithButton *profilePic = new LabelWithButton(app, this);

    QPixmap profile;

    // When there is no pfp
    if (app_data.pfp == "NULL") {
        profile.load("assets/images/KUventpp.png");
    } else {
        // If pfp exists, fetching from the server
        httplib::Result res = app->client->Get("/download/" + app_data.pfp);

        // Checking the result
        if (!res) {
            QMessageBox::critical(
                this,
                "Connection Error",
                "Cannot connect to the server. Please check your connection and try again later."
            );
        }

        if (res->status != httplib::StatusCode::OK_200) {
            QMessageBox::warning(
                this,
                "Pfp Fetch Error",
                QString::fromStdString(res->body)
            );
        }

        profile.loadFromData(
            reinterpret_cast<const uchar*>(res->body.data()),
            res->body.size()
        );
    }

    profilePic->setPixmap(profile);
    profilePic->setFixedSize(100, 100);
    profilePic->setScaledContents(true);

    // Add profilePic to the left side with some spacing
    hLayout15->addSpacing(40); // Add more space to the left of the profile picture
    hLayout15->addWidget(profilePic, 0, Qt::AlignLeft);
	hLayout15->addSpacing(40);

    // Create a vertical layout for the right side
    QVBoxLayout *vlayout = new QVBoxLayout();
    hLayout15->addLayout(vlayout);

    QLabel *usernameLabel = new QLabel("USERNAME");
    usernameLabel->setStyleSheet(
        "font-size: 13pt;"
        "font-weight: bold;"
		"color: #000000;"
    );

    usernameEntryLabel = new QLabel("");
    usernameEntryLabel->setStyleSheet(
        "font-size: 11pt;"
        "font-weight: bold;"
		"color: #7C7C7C;"
    );

    // Add username label and entry label to the vertical layout and align to left
    vlayout->addWidget(usernameLabel, 0, Qt::AlignLeft);
    vlayout->addWidget(usernameEntryLabel, 0, Qt::AlignLeft);
	vlayout->setAlignment(Qt::AlignLeft);
	hLayout15->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout18 = new QHBoxLayout();
	v_profileLayout->addLayout(hLayout18);

	//Horizontal line
	QFrame *line = new QFrame;
    line->setFrameShape(QFrame::HLine); 
    line->setFixedHeight(2);
	line->setFixedWidth(this->width()/1.5);
	line->setStyleSheet("color: #000000;");

	hLayout18->addWidget(line); //Adding line to layout
	hLayout18->setAlignment(Qt::AlignBottom);

	v_profileLayout->addSpacing(10);

	//Email label
	QBoxLayout *hLayout2 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout2);
	
	QLabel *emailLabel = new QLabel("EMAIL");
	emailLabel->setStyleSheet(
			"font-size: 13pt;"
			"font-weight: bold;"
			"color: #000000;"
	);
	hLayout2->addWidget(emailLabel);
	hLayout2->setAlignment(Qt::AlignLeft);

	//email entry 
	QHBoxLayout *hLayout3 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout3);
	hLayout3->addSpacing(10);
	emailEntryLabel = new QLabel("");
	emailEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
			"color: #7C7C7C"
	);
	emailEntryLabel->setFixedSize(270,30);
	hLayout3->addWidget(emailEntryLabel);
	hLayout3->setAlignment(Qt::AlignLeft);

	//line1
	QBoxLayout *hLayout4 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout4);

	//Horizontal line
	QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::HLine); 
    line1->setFixedHeight(2);
	line1->setFixedWidth(this->width()/1.5);
	line1->setStyleSheet("color: #000000;");

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
			"color: #000000;"
	);
	hLayout5->addWidget(contactNoLabel);
	hLayout5->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout6 = new QHBoxLayout();
	v_profileLayout->addLayout(hLayout6);

	contactNoEntryLabel = new ContactNoEntry([=]() {
		std::string number = contactNoEntryLabel->text().toStdString();
		changeProfileData("NUMBER", number);
	});
	contactNoEntryLabel->setText("");
	contactNoEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
			"color: #7C7C7C"
	);
	hLayout6->addWidget(contactNoEntryLabel);
	
	//line2
	QBoxLayout *hLayout7 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout7);

	//Horizontal line
	QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::HLine); 
    line2->setFixedHeight(2);
	line2->setFixedWidth(this->width()/1.5);
	line2->setStyleSheet("color: #000000;");

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
			"color: #000000;"
	);
	hLayout8->addWidget(programBatchLabel);
	hLayout8->setAlignment(Qt::AlignLeft);

	//Program-Batch Entry
	QHBoxLayout *hLayout9 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout9);

	facultyEntryLabel = new FacultyEntry([=]() {
		std::string batch = facultyEntryLabel->text().toStdString();
		changeProfileData("BATCH", batch);
	});
	facultyEntryLabel->setStyleSheet(
			"font-size: 11pt;"
			"font-weight: bold;"
			"color: #7C7C7C"
	);
	hLayout9->addWidget(facultyEntryLabel);

	QBoxLayout *hLayout13 = new QHBoxLayout;
	v_profileLayout->addLayout(hLayout13);

	//Horizontal line
	QFrame *line4 = new QFrame;
    line4->setFrameShape(QFrame::HLine); 
    line4->setFixedHeight(2);
	line4->setFixedWidth(this->width()/1.5);
	line4->setStyleSheet("color: #000000;");

	hLayout13->addWidget(line4); //Adding line to layout
	hLayout13->setAlignment(Qt::AlignLeft);

	v_profileLayout->addSpacing(35);

	//logout button
	QPushButton *logout_button = new QPushButton("Logout");
	logout_button->setStyleSheet("background: #FFFFFF; color: #1E1E1E; border: 1px solid #FF8585; "
                                "border-radius: 8px; height: 32px; width: 89px;"
                                "font-weight: bold;");
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

	usernameEntryLabel->setText(
		QString::fromStdString(app_data.username)
	);

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

