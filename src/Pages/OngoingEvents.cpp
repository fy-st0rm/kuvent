#include "OngoingEvents.h"

void OngoingEventsPage::onAttach() {
	ongoingEventsLayout = new QVBoxLayout(this);
	setLayout(ongoingEventsLayout);

	QLabel *ongoingEventsLabel = new QLabel("Ongoing Events Page", this);
	ongoingEventsLayout->addWidget(ongoingEventsLabel);
}

