#include "UpcomingEvents.h"

UpcomingEventsPage::UpcomingEventsPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *upcomingEventsLayout = new QVBoxLayout(this);
    QLabel *upcomingEventsLabel = new QLabel("Upcoming Events Page", this);
    upcomingEventsLayout->addWidget(upcomingEventsLabel);
}

