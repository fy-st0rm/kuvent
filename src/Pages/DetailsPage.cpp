#include "Pages/DetailsPage.h"

void DetailsPage::onAttach()
{
	getBaseWidget()->setStyleSheet(
		"background-color:" + Theme::dashBg + ";"
		"border-radius: 15px;"
	);
		scrollArea = new QScrollArea();
	scrollArea->setWidgetResizable(true);
	scrollArea->setStyleSheet(
		"QScrollArea { border: none; }"
		"QScrollBar:vertical { border: none; margin: 0px 0px 0px 0px; }"
		"QScrollBar::handle:vertical { border-radius: 5px; background: #FFFFFF; }"
		"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: none; height: 0px; }"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; }"
	);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		containerWidget = new QWidget();
		containerWidget->installEventFilter(this);

		main_layout = new QVBoxLayout(containerWidget);
		scrollArea->setWidget(containerWidget);
		
		QVBoxLayout* baseLayout = new QVBoxLayout(this);
		baseLayout->addWidget(scrollArea);
		setLayout(baseLayout);

}

void DetailsPage::onEntry() {
		setupEventHeader();
		setupOrganizerInfo();
		setupDateInfo();
		main_layout->addSpacing(20);
		setupVenueInfo();
		main_layout->addSpacing(20);
		setupEventDescription();
		main_layout->addSpacing(20);
		setupFlyer();
		setupRegistrationButton();
}

void DetailsPage::setupEventHeader() {
		QHBoxLayout *event_header_layout = new QHBoxLayout;
		main_layout->addLayout(event_header_layout);
		main_layout->setAlignment(Qt::AlignTop);

		eventName = new QLabel();
		eventName->setText(QString(
			"<span style='color: " + Theme::red + ";'>🔴</span>  %1"
		).arg(
			QString::fromStdString(m_event_data["NAME"].asString())
		));
		eventName->setStyleSheet(
				"font-size: 18pt;"
				"font-weight: bold;"
				"color: #000000;"
		);

		closeButton = new QToolButton();
		closeButton->setIcon(QIcon("assets/images/close.png"));
		closeButton->setIconSize(QSize(20, 20));
		closeButton->setContentsMargins(0, 0, 0, 0);
		closeButton->setStyleSheet(
				"border: none;"
		);
		event_header_layout->addWidget(eventName, 0, Qt::AlignLeft);
		event_header_layout->addWidget(closeButton, 1, Qt::AlignRight);

		connect(closeButton, &QToolButton::clicked, this, &DetailsPage::onCloseClick);
}

void DetailsPage::setupOrganizerInfo() {
		QHBoxLayout *organizer_info_layout = new QHBoxLayout;
		main_layout->addLayout(organizer_info_layout);
		main_layout->setAlignment(Qt::AlignTop);

		organizerLabel = new QLabel(
				QString::fromStdString(m_event_data["ORGANIZER"].asString())
		);
		organizerLabel->setStyleSheet(
				"font-weight: bold;"
				"font-size: 14pt;"
				"color: #7C7C7C"
		);
		organizer_info_layout->addSpacing(30);
		organizer_info_layout->addWidget(organizerLabel);
		organizer_info_layout->setAlignment(Qt::AlignLeft);

		main_layout->addSpacing(20);
}

void DetailsPage::setupDateInfo() {
		QHBoxLayout *date_layout = new QHBoxLayout;
		main_layout->addLayout(date_layout);
		QLabel *date = new QLabel("Date");
		date->setStyleSheet(
				"font-weight: bold;"
				"font-size: 14pt;"
				"color: #000000;"
		);
		date_layout->addSpacing(30);
		date_layout->addWidget(date);

		QHBoxLayout *start_end_date_layout = new QHBoxLayout;
		main_layout->addLayout(start_end_date_layout);
		startDate = new QLabel(
				QString::fromStdString(m_event_data["START_DATE"].asString())
		);

		endDate = new QLabel(
				QString::fromStdString(m_event_data["END_DATE"].asString())
		);

		QString startingDate = startDate->text();
		QString endingDate = endDate->text();

		QLabel *eventPeriod = new QLabel(startingDate + " to " + endingDate);
		eventPeriod->setStyleSheet(
				"color: #7C7C7C;"
				"font-size: 12pt;"
				"font-weight: 600;"
		);
		start_end_date_layout->addSpacing(30);
		start_end_date_layout->addWidget(eventPeriod);
}

void DetailsPage::setupVenueInfo() {
		QHBoxLayout *venue_layout = new QHBoxLayout;
		main_layout->addLayout(venue_layout);

		QLabel *venue = new QLabel("Venue");
		venue->setStyleSheet(
				"font-weight: bold;"
				"font-size: 14pt;"
				"color: #000000;"
		);
		venue_layout->addSpacing(30);
		venue_layout->addWidget(venue);
		venue_layout->setAlignment(Qt::AlignLeft);

		QHBoxLayout *venue_location_layout = new QHBoxLayout;
		main_layout->addLayout(venue_location_layout);

		venueLocation = new QLabel(
				QString::fromStdString(m_event_data["VENUE"].asString())
		);
		venueLocation->setStyleSheet(
				"color: #7C7C7C;"
				"font-size: 12pt;"
				"font-weight: 600;"
		);
		venue_location_layout->addSpacing(30);
		venue_location_layout->addWidget(venueLocation);
		venue_location_layout->setAlignment(Qt::AlignLeft);

		QHBoxLayout *venue_desc_layout = new QHBoxLayout;
		main_layout->addLayout(venue_desc_layout);

		venueDescription = new QLabel(
				QString::fromStdString(m_event_data["VENUE_DESC"].asString())
		);
		venueDescription->setStyleSheet(
				"color: #7C7C7C;"
				"font-size: 12pt;"
		);
		venue_desc_layout->addSpacing(30);
		venue_desc_layout->addWidget(venueDescription);
		venue_desc_layout->setAlignment(Qt::AlignLeft);
}

void DetailsPage::setupEventDescription() {
		QHBoxLayout *hLayout8 = new QHBoxLayout;
		main_layout->addLayout(hLayout8);

		QLabel *about = new QLabel("About the event");
		about->setStyleSheet(
				"font-weight: bold;"
				"font-size: 14pt;"
				"color: #000000;"
		);
		hLayout8->addSpacing(30);
		hLayout8->addWidget(about);
		hLayout8->setAlignment(Qt::AlignLeft);

		QHBoxLayout *desc_layout = new QHBoxLayout;
		main_layout->addLayout(desc_layout);

		eventDescription = new QLabel(
				QString::fromStdString(m_event_data["DESC"].asString())
		);
		eventDescription->setStyleSheet(
				"color: #7C7C7C;"
				"font-size: 12pt;"
		);
		desc_layout->addSpacing(30);
		desc_layout->addWidget(eventDescription);
		desc_layout->setAlignment(Qt::AlignLeft);

		main_layout->addSpacing(15);
}

void DetailsPage::setupFlyer() {
		QHBoxLayout *flyer_layout = new QHBoxLayout;
		main_layout->addLayout(flyer_layout);

		std::string flyer_id = getFlyerId();
		httplib::Result res = app->client->Get("/download/" + flyer_id);

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
		QPixmap flyerPixmap;
		flyerPixmap.loadFromData(
				reinterpret_cast<const uchar*>(res->body.data()),
				res->body.size()
		);

		// Set the pixmap and scale it to maintain aspect ratio
		eventFlyer->setPixmap(flyerPixmap.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		eventFlyer->setFixedSize(400, 400); // Ensures the label size is fixed

		flyer_layout->addSpacing(30);
		flyer_layout->addWidget(eventFlyer);
		flyer_layout->setAlignment(Qt::AlignLeft);

		// Create a layout for the registration button
		registrationLayout = new QHBoxLayout;
		main_layout->addLayout(registrationLayout);
}

void DetailsPage::setupRegistrationButton() {
		if (m_exit_page == "OngoingPage")
				return;

		AppData app_data = m_app->getAppData();
		if (app_data.account_type == ORGANIZER)
				return;

		button = nullptr;
		if (!isUserRegistered()) {
				// Register button
				button = new QPushButton("Register", this);
		} else {
				// Leave button
				button = new QPushButton("Leave", this);
		}

		applyShadow(button);

		if (button) {
				button->setFixedSize(80, 37.5);
				button->setStyleSheet(
						"background-color: #7469B6;"
						"border-radius: 5px;"
						"color: white;"
						"font-weight: bold;"
				);
				if (!isUserRegistered()) {
						connect(button, &QPushButton::clicked, this, &DetailsPage::onRegisterClick);
				} else {
						connect(button, &QPushButton::clicked, this, &DetailsPage::onLeaveClick);
				}
				registrationLayout->addWidget(button, 0, Qt::AlignBottom | Qt::AlignRight);
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
	// passive aggression?
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
	
	if (button != nullptr) {
		delete button;
		button = nullptr;
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
