#include "OngoingEvents.h"
#include "Widgets/PackEvent.h"
#include "Pages/DetailsPage.h"
#include "utils.h"

void OngoingEventsPage::onAttach() {
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

void OngoingEventsPage::onEntry() {
    try {
        Json::Value events = fetchEvents();
        Json::Value ongoingEvents = filterOngoingEvents(events);
        generateDetailsPages(ongoingEvents);
        displayOngoingEvents(ongoingEvents);
    } 
	catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    }
}

Json::Value OngoingEventsPage::fetchEvents() {
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

Json::Value OngoingEventsPage::filterOngoingEvents(const Json::Value& events) {
    Json::Value ongoingEvents;
    std::time_t currentTime = std::time(nullptr);
    
    for (const auto& event : events) {
        std::time_t startTime = dateStringToTimestamp(event["START_DATE"].asString());
        std::time_t endTime = dateStringToTimestamp(event["END_DATE"].asString());
        
        if (startTime <= currentTime && endTime >= currentTime) {
            ongoingEvents.append(event);
        }
    }
    return ongoingEvents;
}

void OngoingEventsPage::displayOngoingEvents(const Json::Value& ongoingEvents) {
    for (const auto& event : ongoingEvents) {
        Json::Value flyers = fetchFlyers(event["ID"].asString());
        
        QString eventName = QString::fromStdString(event["NAME"].asString());
        QString organizer = QString::fromStdString(event["ORGANIZER"].asString());
        std::string flyerId = flyers["flyers"][0].asString();
        
        PackEvent* eventWidget = new PackEvent(containerWidget, app->client, flyerId, organizer, eventName);
        eventWidget->setFixedSize(310, 400);
        eventWidgets.append(eventWidget);
        
        connectDetailsButton(eventWidget, event);
    }
    adjustLayout();
}

bool OngoingEventsPage::eventFilter(QObject *obj, QEvent *event) {
    if (obj == containerWidget && event->type() == QEvent::Resize) {
        adjustLayout();
        return true;
    }
    return QObject::eventFilter(obj, event);
}

Json::Value OngoingEventsPage::fetchFlyers(const std::string& eventId) {
    httplib::Result res = app->client->Get("/get_flyer/" + eventId);
    if (!res || res->status != 200) {
        throw std::runtime_error(res ? res->body : "Cannot connect to the server");
    }
    
    Json::Value response;
    Json::Reader reader;
    if (!reader.parse(res->body, response)) {
        throw std::runtime_error("Failed to parse flyer data");
    }
    return response;
}

void OngoingEventsPage::connectDetailsButton(PackEvent* eventWidget, const Json::Value& event) {
    connect(eventWidget->getDetailsButton(), &QPushButton::clicked, this,
            [this, event]() {
                pg_switcher->switchPage(event["ID"].asString());
            });
}

void OngoingEventsPage::adjustLayout() {
    int availableWidth = containerWidget->width() - ongoingEventsLayout->contentsMargins().left() - ongoingEventsLayout->contentsMargins().right();
    int itemWidth = 310 + ongoingEventsLayout->spacing();
    int itemsPerRow = std::max(1, availableWidth / itemWidth);

    for (int i = 0; i < eventWidgets.size(); ++i) {
        int row = i / itemsPerRow;
        int col = i % itemsPerRow;
        ongoingEventsLayout->addWidget(eventWidgets[i], row, col);
    }
}

void OngoingEventsPage::onExit() {
	QLayoutItem* item;
	while ( ( item = ongoingEventsLayout->layout()->takeAt( 0 ) ) != NULL )
	{
		delete item->widget();
		delete item;
	}
}

void OngoingEventsPage::generateDetailsPages(const Json::Value& events) {
	for (auto event : events) {
		qDebug("haax");
		// pg_switcher->addPage<DetailsPage>(
		// 	event["ID"].asString(),
		// 	event,
		// 	"OngoingPage"
		// );
		qDebug("haaax");

	}
}