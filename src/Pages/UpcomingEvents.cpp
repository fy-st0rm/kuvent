#include "UpcomingEvents.h"
#include "utils.h"

void UpcomingEventsPage::onAttach() {
	QScrollArea *scrollArea = new QScrollArea();
	scrollArea->setWidgetResizable(true);
	scrollArea->setStyleSheet(
		"QScrollArea {"
		"border: none;"
		"}"
		"QScrollBar:vertical {"
		"border: none;"
		"margin: 0px 0px 0px 0px;"
		"}"
		"QScrollBar::handle:vertical {"
		"border-radius: 5px;"
		"background: #FFFFFF;"
		"}"
		"QScrollBar::add-line:vertical {"
		"background: none;"
		"height: 0px;"
		"}"
		"QScrollBar::sub-line:vertical {"
		"background: none;"
		"height: 0px;"
		"}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
		"background: none;"
		"}"
	);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	containerWidget = new QWidget();

	upcomingEventsLayout = new QGridLayout(containerWidget);
	upcomingEventsLayout->setSpacing(40);
	
	scrollArea->setWidget(containerWidget);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(scrollArea); 
	
	setLayout(mainLayout);
}

void UpcomingEventsPage::onEntry() {
	// Getting all the events
	httplib::Result res = app->client->Get("/get_event");

	// Checking the response
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Event Fetching Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	// Abstracting response
	Json::Value events;
	Json::Reader reader;
	reader.parse(res->body, events);

	// This holds all the upcoming events
	Json::Value upcoming_events;

	for (auto event: events) {
		std::string start_date = event["START_DATE"].asString();
		std::string end_date = event["END_DATE"].asString();

		// Converting string time to numeric timestamps
		std::time_t start_ts = dateStringToTimestamp(start_date);
		std::time_t end_ts = dateStringToTimestamp(end_date);
		std::time_t curr_ts = std::time(nullptr);

		// Checking if its an upcoming event
		if (start_ts > curr_ts && end_ts > curr_ts) {
			upcoming_events.append(event);
		}
	}

	int row = 0;
	int col = 0;

	// Generating details page
	generateDetailsPages(upcoming_events);

	for (auto event: upcoming_events) {
		// Getting the flyers of the event
		httplib::Result res = app->client->Get("/get_flyer/" + event["ID"].asString());

		// Checking the response
		if (!res) {
			QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
			return;
		}

		if (res->status != httplib::StatusCode::OK_200) {
			QMessageBox::warning(
				this,
				"FLyer Fetching Error",
				QString::fromStdString(res->body)
			);
			return;
		}

		// Parsing the response
		Json::Value response;
		Json::Reader reader;
		reader.parse(res->body, response);

		Json::Value flyers = response["flyers"];

		// Extracting the data
		QString event_name = QString::fromStdString(event["NAME"].asString());
		QString organizer = QString::fromStdString(event["ORGANIZER"].asString());

		// NOTE: Using index 0 as only one flyer can be inserted at the moment
		std::string flyer_id = flyers[0].asString();

		PackEvent* event_widget = new PackEvent(containerWidget, app->client, flyer_id, organizer, event_name);
		upcomingEventsLayout->addWidget(event_widget, row, col, Qt::AlignTop | Qt::AlignLeft);
		
		// Connect the details button of each event
		connect(
			event_widget->getDetailsButton(),
			&QPushButton::clicked, this,
			[this, event, event_widget]() {
				pg_switcher->switchPage(event["ID"].asString());
		});

		// TODO: Find a better alternative
		col++;
		if (col == 3) {
			row++;
			col = 0;
		}
	}
}

void UpcomingEventsPage::onExit() {
	QLayoutItem* item;
	while ( ( item = upcomingEventsLayout->layout()->takeAt( 0 ) ) != NULL )
	{
		delete item->widget();
		delete item;
	}
}

void UpcomingEventsPage::generateDetailsPages(const Json::Value& events) {
	for (auto event : events) {
		pg_switcher->addPage<DetailsPage>(
			event["ID"].asString(),
			event,
			"UpcomingPage"
		);
	}
}
