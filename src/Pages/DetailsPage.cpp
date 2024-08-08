#include "Pages/DetailsPage.h"

void DetailsPage::onAttach()
{
	main_layout = new QVBoxLayout();
	setLayout(main_layout);
}

void DetailsPage::onEntry() {
	QHBoxLayout *hLayout1 = new QHBoxLayout;
	main_layout->addLayout(hLayout1);
	main_layout->setAlignment(Qt::AlignTop);

	eventName = new QLabel(
		QString::fromUtf8("🔴")
		+ QString::fromStdString(m_event_data["NAME"].asString())
	);
	eventName->setStyleSheet(
		"font-size: 14pt;"
		"font-weight: bold;"
	);

	closeButton = new QToolButton();
	closeButton->setIcon(QIcon("assets/images/close.png"));
	closeButton->setIconSize(QSize(20,20));
	closeButton->setContentsMargins(0,0,0,0);
	closeButton->setStyleSheet(
		"border: none;"
	);
	hLayout1->addWidget(eventName, 0, Qt::AlignLeft);
	hLayout1->addWidget(closeButton, 0, Qt::AlignRight);

	connect(closeButton, &QToolButton::clicked, this, &DetailsPage::onCloseClick);
	
	QHBoxLayout *hLayout2 = new QHBoxLayout;
	main_layout->addLayout(hLayout2);
	main_layout->setAlignment(Qt::AlignTop);

	organizerLabel = new QLabel(
		QString::fromStdString(m_event_data["ORGANIZER"].asString())
	);
	hLayout2->addSpacing(30);
	hLayout2->addWidget(organizerLabel);
	hLayout2->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout3 = new QHBoxLayout;
	main_layout->addLayout(hLayout3);
	QLabel *date = new QLabel("Date");
	date->setStyleSheet(
			"font-weight: bold;"
	);
	hLayout3->addSpacing(30);
	hLayout3->addWidget(date);

	QHBoxLayout *hLayout4 = new QHBoxLayout;
	main_layout->addLayout(hLayout4);
	startDate = new QLabel(
		QString::fromStdString(m_event_data["START_DATE"].asString())
	);
	endDate = new QLabel(
		QString::fromStdString(m_event_data["END_DATE"].asString())
	);

	QString startingDate = startDate->text();
	QString endingDate = endDate->text();

	QLabel *eventPeriod = new QLabel(startingDate + " to " + endingDate);
	hLayout4->addSpacing(30);
	hLayout4->addWidget(eventPeriod);

	QHBoxLayout *hLayout5 = new QHBoxLayout;
	main_layout->addLayout(hLayout5);

	QLabel *venue = new QLabel("Venue");
	venue->setStyleSheet(
			"font-weight: bold;"
	);
	hLayout5->addSpacing(30);
	hLayout5->addWidget(venue);
	hLayout5->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout6 = new QHBoxLayout;
	main_layout->addLayout(hLayout6);

	venueLocation = new QLabel(
		QString::fromStdString(m_event_data["VENUE"].asString())
	);
	hLayout6->addSpacing(30);
	hLayout6->addWidget(venueLocation);
	hLayout6->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout7 = new QHBoxLayout;
	main_layout->addLayout(hLayout7);

	venueDescription = new QLabel(
		QString::fromStdString(m_event_data["VENUE_DESC"].asString())
	);
	venueDescription->setStyleSheet(
			"color: #3E7689;"
	);
	hLayout7->addSpacing(30);
	hLayout7->addWidget(venueDescription);
	hLayout7->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout8 = new QHBoxLayout;
	main_layout->addLayout(hLayout8);

	QLabel *about = new QLabel("About the event");
	about->setStyleSheet(
			"font-weight: bold;"
	);
	hLayout8->addSpacing(30);
	hLayout8->addWidget(about);
	hLayout8->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout9 = new QHBoxLayout;
	main_layout->addLayout(hLayout9);

	eventDescription = new QLabel(
		QString::fromStdString(m_event_data["DESC"].asString())
	);
	hLayout9->addSpacing(30);
	hLayout9->addWidget(eventDescription);
	hLayout9->setAlignment(Qt::AlignLeft);

	QHBoxLayout *hLayout10 = new QHBoxLayout;
	main_layout->addLayout(hLayout10);

	std::string flyer_id = getFlyerId();
	httplib::Result res = app->client->Get("/download/" + flyer_id);

	// Checking the result
	if (!res) {
		QMessageBox::critical(
			this,
			"Connection Error",
			"Cannot connect to the server. Please check your connection and try again later."
		);
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Flyer Fetch Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	eventFlyer = new QLabel();
	QPixmap flyer;
	flyer.loadFromData(
		reinterpret_cast<const uchar*>(res->body.data()),
		res->body.size()
	);
	eventFlyer->setPixmap(flyer);
	eventFlyer->setFixedSize(400,400);
	eventFlyer->setScaledContents(true);

	hLayout10->addSpacing(30);
	hLayout10->addWidget(eventFlyer);
	hLayout10->setAlignment(Qt::AlignLeft);

	if (m_exit_page == "OngoingPage")
		return;

	if (!isUserRegistered()) {
		// Register button
		registerButton = new QPushButton("Register", this);
		registerButton->setStyleSheet(
			"background-color: purple;"
		);
		connect(registerButton, &QPushButton::clicked, this, &DetailsPage::onRegisterClick);
		hLayout10->addWidget(registerButton, 0, Qt::AlignBottom | Qt::AlignRight);
	} else {
		// Leave button
		leaveButton = new QPushButton("Leave", this);
		leaveButton->setStyleSheet(
			"background-color: purple;"
		);
		connect(leaveButton, &QPushButton::clicked, this, &DetailsPage::onLeaveClick);
		hLayout10->addWidget(leaveButton, 0, Qt::AlignBottom | Qt::AlignRight);
	}
}

void DetailsPage::onCloseClick()
{
	pg_switcher->switchPage(m_exit_page);
}

std::string DetailsPage::getFlyerId() {
	httplib::Result res = app->client->Get("/get_flyer/" + m_event_data["ID"].asString());

	// Checking the result
	if (!res) {
		QMessageBox::critical(
			this,
			"Connection Error",
			"Cannot connect to the server. Please check your connection and try again later."
		);
		return "";
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Flyer Fetch Error",
			QString::fromStdString(res->body)
		);
		return "";
	}

	// Parsing the response
	Json::Value response;
	Json::Reader reader;
	reader.parse(res->body, response);

	Json::Value flyers = response["flyers"];

	// NOTE: Returning only one flyer id as we support only one flyer
	return flyers[0].asString();
}

void DetailsPage::onExit() {
	QLayoutItem* item;
	while ( ( item = main_layout->layout()->takeAt( 0 ) ) != NULL )
	{
		delete item->widget();
		delete item;
	}

	if (closeButton != nullptr) {
		delete closeButton;
		closeButton = nullptr;
	}
	
	if (registerButton != nullptr) {
		delete registerButton;
		registerButton = nullptr;
	}

	if (leaveButton != nullptr) {
		delete leaveButton;
		leaveButton = nullptr;
	}
}

void DetailsPage::onRegisterClick() {
	AppData app_data = m_app->getAppData();

	Json::Value payload;
	Json::StyledWriter writer;
	payload["user_id"] = app_data.id;
	payload["event_id"] = m_event_data["ID"];

	httplib::Result res = m_app->client->Post(
		"/join_event",
		writer.write(payload),
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
			"Leave event error",
			QString::fromStdString(res->body)
		);
		return;
	}

	onExit();
	onEntry();
}

void DetailsPage::onLeaveClick() {
	AppData app_data = m_app->getAppData();

	Json::Value payload;
	Json::StyledWriter writer;
	payload["user_id"] = app_data.id;
	payload["event_id"] = m_event_data["ID"];

	httplib::Result res = m_app->client->Post(
		"/leave_event",
		writer.write(payload),
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
			"Leave event error",
			QString::fromStdString(res->body)
		);
		return;
	}

	onExit();
	onEntry();
}

bool DetailsPage::isUserRegistered() {
	AppData app_data = m_app->getAppData();

	Json::Value payload;
	Json::StyledWriter writer;
	payload["user_id"] = app_data.id;
	payload["event_id"] = m_event_data["ID"];

	httplib::Result res = m_app->client->Post(
		"/is_registered",
		writer.write(payload),
		"application/json"
	);

	// Checking the response
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return false;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Register status fetch error",
			QString::fromStdString(res->body)
		);
		return false;
	}

	// Reading the response
	Json::Value res_data;
	Json::Reader reader;
	reader.parse(res->body, res_data);

	return res_data["registered"].asBool();
}
