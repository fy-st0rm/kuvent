#include "UpcomingEvents.h"

void UpcomingEventsPage::onAttach() {
	upcomingEventsLayout = new QVBoxLayout(this);
	upcomingEventsLabel = new QLabel("Upcoming Events Page", this);
	upcomingEventsLayout->addWidget(upcomingEventsLabel);

	setLayout(upcomingEventsLayout);
}

