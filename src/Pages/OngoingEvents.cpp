#include "OngoingEvents.h"

void OngoingEventsPage::onAttach() 
{
    ongoingEventsLayout = new QGridLayout(this);
    setLayout(ongoingEventsLayout);

    QString event_name = "KUGameJam";
    QString organizer = "KUCC";
    QString flyer_path = "assets/images/gameJam.png";

    PackEvent* event = new PackEvent(this, flyer_path, organizer, event_name);
    ongoingEventsLayout->addWidget(event, 0, 0, Qt::AlignCenter);
}