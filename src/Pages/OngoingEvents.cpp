#include "OngoingEvents.h"
#include "Widgets/PackEvent.h"
#include "Pages/DetailsPage.h"
#include "utils.h"

void OngoingEventsPage::onAttach() 
{
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

	ongoingEventsLayout = new QGridLayout(containerWidget);
	ongoingEventsLayout->setSpacing(40);
	
	scrollArea->setWidget(containerWidget);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(scrollArea); 
	
	setLayout(mainLayout);
}

void OngoingEventsPage::onEntry() {
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

	// This holds all the ongoing events
	Json::Value ongoing_events;

	for (auto event: events) {
		std::string start_date = event["START_DATE"].asString();
		std::string end_date = event["END_DATE"].asString();

		// Converting string time to numeric timestamps
		std::time_t start_ts = dateStringToTimestamp(start_date);
		std::time_t end_ts = dateStringToTimestamp(end_date);
		std::time_t curr_ts = std::time(nullptr);

		// Checking if its an ongoing event
		if (start_ts <= curr_ts && end_ts >= curr_ts) {
			ongoing_events.append(event);
		}
	}

	int row = 0;
	int col = 0;

	for (auto event: ongoing_events) {
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
		ongoingEventsLayout->addWidget(event_widget, row, col, Qt::AlignCenter);
		
		// Connect the details button of each event
		connect(event_widget->getDetailsButton(), &QPushButton::clicked, this, [this, event_widget]() {
				// Handle the details button click here
		});

		// TODO: Find a better alternative
		col++;
		if (col == 3) {
			row++;
			col = 0;
		}
	}
}
