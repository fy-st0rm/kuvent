#include "Widgets/MyEventsDetails.h"

MyEventsDetails::MyEventsDetails (QWidget *parent)
    : QWidget(parent)
{
    QWidget *widget = new QWidget(this);

    QHBoxLayout *mainLayout = new QHBoxLayout(widget);
    mainLayout->addSpacing(55);

    usernameDetail = new QLabel("", this);
    mainLayout->addWidget(usernameDetail);
    usernameDetail->setMinimumSize(50, 30);

    batchDetail = new QLabel("", this);
    mainLayout->addWidget(batchDetail);
    batchDetail->setMinimumSize(50, 30);

    emailDetail = new QLabel("", this);
    mainLayout->addWidget(emailDetail);
    emailDetail->setMinimumSize(50, 30);

    contactDetail = new QLabel("", this);
    mainLayout->addWidget(contactDetail);
    contactDetail->setMinimumSize(50, 30);
    
    setLayout(mainLayout);
}