#include "OngoingEvents.h"

void OngoingEventsPage::onAttach() 
{
    ongoingEventsLayout = new QGridLayout(this);
    setLayout(ongoingEventsLayout);

    QString event_name = "KUGameJam";
    QString organizer = "KUCC";
    QString flyer_path = "assets/images/gameJam.png";
	for (int i = 0 ; i < 3; i++)
	{

		PackEvent* event = new PackEvent(this, flyer_path, organizer, event_name);
		ongoingEventsLayout->addWidget(event, 0, i, Qt::AlignCenter);

	}
}
