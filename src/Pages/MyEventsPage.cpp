#include "Pages/MyEventsPage.h"
#include "Widgets/UserDetailsWidget.h"

void MyEventsPage::onAttach() {
		QScrollArea *scrollArea = new QScrollArea();
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

		ongoingEventsLayout = new QGridLayout(containerWidget);
		ongoingEventsLayout->setSpacing(10);
		ongoingEventsLayout->setContentsMargins(10, 10, 10, 10);
		
		scrollArea->setWidget(containerWidget);

		QVBoxLayout *mainLayout = new QVBoxLayout(this);
		mainLayout->addWidget(scrollArea);
		
		setLayout(mainLayout);
}

void MyEventsPage::onEntry() {
		try {
				Json::Value events = fetchEvents();
				Json::Value myEvents = filterMyEvents(events);
				generateDetailsPages(myEvents);
				displayMyEvents(myEvents);
		} 
	catch (const std::exception& e) {
				QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
		}
}

Json::Value MyEventsPage::fetchEvents() {
		httplib::Result res = app->client->Get("/get_event");
		if (!res || res->status != 200) {
				throw std::runtime_error(res ? res->body : "Cannot connect to the server");
		}
		
		Json::Value events;
		Json::Reader reader;
		if (!reader.parse(res->body, events)) {
				throw std::runtime_error("Failed to parse event data");
		}
		return events;
}

Json::Value MyEventsPage::filterMyEvents(const Json::Value& events) {
		Json::Value myEvents;
		std::time_t currentTime = std::time(nullptr);
		
	AppData app_data = app->getAppData();
		for (const auto& event : events) {
			if (event["ORGANIZER_ID"].asString() == app_data.id) {
				myEvents.append(event);
			}
		}
		return myEvents;
}

void MyEventsPage::displayMyEvents(const Json::Value& myEvents) {
		AppData app_data = app->getAppData();
		for (const auto& event : myEvents) {
				Json::Value flyers = fetchFlyers(event["ID"].asString());
				
				QString eventName = QString::fromStdString(event["NAME"].asString());
				QString organizer = QString::fromStdString(event["ORGANIZER"].asString());
				QString organizer_id = QString::fromStdString(event["ORGANIZER_ID"].asString());
				bool is_organizer = organizer_id.toStdString() == app_data.id;
				std::string flyerId = flyers["flyers"][0].asString();
				
				PackEvent* eventWidget = new PackEvent(
					containerWidget,
					app->client,
					flyerId,
					organizer,
					eventName,
					is_organizer
				);
				eventWidget->setFixedSize(310, 400);
				eventWidgets.append(eventWidget);
				
				connect(
					eventWidget->getDetailsButton(),
					&QPushButton::clicked, this,
					[this, event, eventWidget]() {
						pg_switcher->switchPage("test");
				});
				connect(
					eventWidget->getDeleteButton(),
					&QPushButton::clicked, this,
					[this, event]() {
						deleteEvent(event["ID"].asString());
					}
				);
		}
		adjustLayout();
}

bool MyEventsPage::eventFilter(QObject *obj, QEvent *event) {
		if (obj == containerWidget && event->type() == QEvent::Resize) {
				adjustLayout();
				return true;
		}
		return QObject::eventFilter(obj, event);
}

Json::Value MyEventsPage::fetchFlyers(const std::string& eventId) {
		httplib::Result res = app->client->Get("/get_flyer/" + eventId);
		if (!res || res->status != httplib::StatusCode::OK_200) {
				throw std::runtime_error(res ? res->body : "Cannot connect to the server");
		}
		
		Json::Value response;
		Json::Reader reader;
		if (!reader.parse(res->body, response)) {
				throw std::runtime_error("Failed to parse flyer data");
		}
		return response;
}

void MyEventsPage::adjustLayout() {
		int availableWidth = containerWidget->width() - ongoingEventsLayout->contentsMargins().left() - ongoingEventsLayout->contentsMargins().right();
		int itemWidth = 310 + ongoingEventsLayout->spacing();
		int itemsPerRow = qMax(1, availableWidth / itemWidth);

		for (int i = 0; i < eventWidgets.size(); ++i) {
				int row = i / itemsPerRow;
				int col = i % itemsPerRow;
				ongoingEventsLayout->addWidget(eventWidgets[i], row, col);
				ongoingEventsLayout->setAlignment(Qt::AlignTop);
				ongoingEventsLayout->setSpacing(20);
		}
}

void MyEventsPage::onExit() {
	qDeleteAll(eventWidgets);
		eventWidgets.clear();
}

void MyEventsPage::generateDetailsPages(const Json::Value& events) {
		if(!pg_switcher){
				qDebug () << "pg_switcher not initialized";
				return;
		}
	for (auto event : events) {
		pg_switcher->addPage<ParticipantList>("test");
	}
}

void MyEventsPage::deleteEvent(const std::string& event_id) {
	Json::Value payload;
	Json::StyledWriter writer;
	payload["event_id"] = event_id;

	httplib::Result res = app->client->Post(
		"/delete_event",
		writer.write(payload),
		"application/json"
	);

	// Checking the result
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Delete Event Error",
			QString::fromStdString(res->body)
		);
		return;
	}

	QMessageBox::information(
		this,
		"Sucess",
		QString::fromStdString(res->body)
	);

	// Refreshing the page
	onExit();
	onEntry();
}
