#include "Pages/ParticipantList.h"

void ParticipantList::onAttach()
{
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
	containerLayout = new QVBoxLayout(containerWidget);
	containerLayout->setSpacing(10);
	containerLayout->setContentsMargins(10, 10, 10, 10);

	QHBoxLayout *hLayout1 = new QHBoxLayout();
	containerLayout->addLayout(hLayout1);

	QLabel *eventName = new QLabel(
		QString::fromStdString(m_event["NAME"].asString()),
		this
	);
	eventName->setStyleSheet(
			"font-weight: bold;"
			"font-size: 12pt;"
			);
	hLayout1->addWidget(eventName);

	QHBoxLayout *hLayout2 = new QHBoxLayout();
	containerLayout->addLayout(hLayout2);

	QLabel *organizerName = new QLabel(
		QString::fromStdString(m_event["ORGANIZER"].asString()),
		this
	);
	organizerName->setStyleSheet(
			"font-size: 10pt;"
			);
	hLayout2->addWidget(organizerName);

	containerLayout->addSpacing(50);

	QHBoxLayout *hLayout3 = new QHBoxLayout();
	containerLayout->addLayout(hLayout3);

	hLayout3->addSpacing(40);
	QLabel *usernameLabel = new QLabel("Username", this);
	usernameLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
	hLayout3->addWidget(usernameLabel);

	QLabel *batchLabel = new QLabel("Program Batch", this);
	batchLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
	hLayout3->addWidget(batchLabel);

	QLabel *emailLabel = new QLabel("Email", this);
	emailLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
	hLayout3->addWidget(emailLabel);

	QLabel *contactLabel = new QLabel("Contact No.", this);
	contactLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
	hLayout3->addWidget(contactLabel);

	scrollArea->setWidget(containerWidget);

	setCentralWidget(scrollArea);

	setLayout(containerLayout);
}

void ParticipantList::onEntry() {
	displayParticipants();
}

void ParticipantList::onExit() {
	while (!m_details.empty()) {
		delete m_details.back();
		m_details.pop_back();
	}
}

void ParticipantList::displayParticipants() {
	httplib::Result res = app->client->Get(
		"/get_participants/" + m_event["ID"].asString()
	);

	// Checking the result
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Participants fetching Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	// Reading the data
	Json::Value data;
	Json::Reader reader;
	reader.parse(res->body, data);

	for (auto user_id : data["participants"]) {

		// Fetching the user profile
		httplib::Result res = app->client->Get(
			"/get_profile/" + user_id.asString()
		);

		// Checking the result
		if (!res) {
			QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
			return;
		}

		if (res->status != httplib::StatusCode::OK_200) {
			QMessageBox::warning(
				this,
				"Profile fetching Error",
				QString::fromStdString(res->body)
			);
			return;
		}

		// Reading the data
		Json::Value user_data;
		Json::Reader reader;
		reader.parse(res->body, user_data);

		MyEventsDetails* user_details = new MyEventsDetails(
			QString::fromStdString(user_data["username"].asString()),
			QString::fromStdString(user_data["batch"].asString()),
			QString::fromStdString(user_data["email"].asString()),
			QString::fromStdString(user_data["number"].asString())
		);
		m_details.push_back(user_details);
		containerLayout->addWidget(user_details, Qt::AlignTop);
	}
}
