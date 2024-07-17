#include "OngoingEvents.h"

OngoingEventsPage::OngoingEventsPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *ongoingEventsLayout = new QVBoxLayout(this);
    QLabel *ongoingEventsLabel = new QLabel("Ongoing Events Page", this);
    ongoingEventsLayout->addWidget(ongoingEventsLabel);

}

