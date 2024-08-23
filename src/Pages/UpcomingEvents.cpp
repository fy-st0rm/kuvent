#include "UpcomingEvents.h"
#include "utils.h"

void UpcomingEventsPage::onAttach() {
	getBaseWidget()->setStyleSheet(
		"background-color:" + Theme::dashBg + ";"
		"border-radius: 15px;"
	);

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

		upcomingEventsLayout = new QGridLayout(containerWidget);
		upcomingEventsLayout->setSpacing(10);
		upcomingEventsLayout->setContentsMargins(10, 10, 10, 10);
		
		scrollArea->setWidget(containerWidget);

		mainLayout = new QVBoxLayout(this);
		mainLayout->addWidget(scrollArea);
		setLayout(mainLayout);
}

void UpcomingEventsPage::onEntry() {
	try {
		Json::Value events = fetchEvents();
		Json::Value upcomingEvents = filterUpcomingEvents(events);

		if (upcomingEvents.size() > 0) {
			generateDetailsPages(upcomingEvents);
			displayUpcomingEvents(upcomingEvents);
		}
		else {
			// Adding a placeholder image when no events are there
			placeholder_layout = new QHBoxLayout;
			placeholder_layout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
			QPixmap pixmap("assets/images/no_upcoming.png");
			placeholder = new QLabel();
			placeholder->setPixmap(pixmap);
			placeholder->setFixedSize(800, 600);
			placeholder->setPixmap(pixmap.scaled(
				800, 600,
				Qt::KeepAspectRatio, Qt::SmoothTransformation
			));
			placeholder->setStyleSheet(
				"QLabel {"
				"  background-color: transparent;"
				"}"
			);
			placeholder->setAlignment(Qt::AlignCenter);

			placeholder_layout->addStretch();
			placeholder_layout->addWidget(placeholder);
			placeholder_layout->addStretch();

			mainLayout->addLayout(placeholder_layout, Qt::AlignCenter);
		}
	} catch (const std::exception& e) {
		QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
	}
}

Json::Value UpcomingEventsPage::fetchEvents() {
		httplib::Result res = app->client->Get("/get_event");
		if (!res || res->status != httplib::StatusCode::OK_200) {
				throw std::runtime_error(res ? res->body : "Cannot connect to the server");
		}
		
		Json::Value events;
		Json::Reader reader;
		if (!reader.parse(res->body, events)) {
				throw std::runtime_error("Failed to parse event data");
		}
		return events;
}

Json::Value UpcomingEventsPage::filterUpcomingEvents(const Json::Value& events) {
		Json::Value upcomingEvents;
		std::time_t currentTime = std::time(nullptr);
		
		for (const auto& event : events) {
				std::time_t startTime = dateStringToTimestamp(event["START_DATE"].asString());
				std::time_t endTime = dateStringToTimestamp(event["END_DATE"].asString());
				
				if (startTime > currentTime && endTime > currentTime) {
						upcomingEvents.append(event);
				}
		}
		return upcomingEvents;
}

void UpcomingEventsPage::displayUpcomingEvents(const Json::Value& upcomingEvents) {
		for (const auto& event : upcomingEvents) {
				Json::Value flyers = fetchFlyers(event["ID"].asString());
				
				QString eventName = QString::fromStdString(event["NAME"].asString());
				QString organizer = QString::fromStdString(event["ORGANIZER"].asString());
				std::string flyerId = flyers["flyers"][0].asString();
				
				PackEvent* eventWidget = new PackEvent(
					containerWidget,
					app,
					flyerId,
					organizer,
					eventName,
					event["ID"].asString(),
					false
				);
				eventWidget->setFixedSize(310, 400);
				eventWidgets.append(eventWidget);
				
				connect(
			eventWidget->getDetailsButton(),
			&QPushButton::clicked, this,
			[this, event, eventWidget]() {
				pg_switcher->switchPage(event["ID"].asString());
		});
		}
		adjustLayout();
}

bool UpcomingEventsPage::eventFilter(QObject *obj, QEvent *event) {
		if (obj == containerWidget && event->type() == QEvent::Resize) {
				adjustLayout();
				return true;
		}
		return QObject::eventFilter(obj, event);
}

Json::Value UpcomingEventsPage::fetchFlyers(const std::string& eventId) {
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

void UpcomingEventsPage::adjustLayout() {
		int availableWidth = containerWidget->width() - upcomingEventsLayout->contentsMargins().left() - upcomingEventsLayout->contentsMargins().right();
		int itemWidth = 310 + upcomingEventsLayout->spacing();
		int itemsPerRow = qMax(1, availableWidth / itemWidth);

		for (int i = 0; i < eventWidgets.size(); ++i) {
				int row = i / itemsPerRow;
				int col = i % itemsPerRow;
				upcomingEventsLayout->addWidget(eventWidgets[i], row, col);
				upcomingEventsLayout->setAlignment(Qt::AlignTop);
				upcomingEventsLayout->setSpacing(20);
		}
}

void UpcomingEventsPage::onExit() {
		qDeleteAll(eventWidgets);
		eventWidgets.clear();

	if (placeholder != nullptr) {
		delete placeholder;
		placeholder = nullptr;
	}
	if (placeholder_layout != nullptr) {
		delete placeholder_layout;
		placeholder_layout = nullptr;
	}
}

void UpcomingEventsPage::generateDetailsPages(const Json::Value& events) {
		for (auto event : events) {
				pg_switcher->addPage<DetailsPage>(
						event["ID"].asString(),
						app,
						event,
						"UpcomingPage"
				);
		}
}
