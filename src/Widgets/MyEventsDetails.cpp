#include "Widgets/MyEventsDetails.h"


MyEventsDetails::MyEventsDetails (
	QString username,
	QString batch,
	QString email,
	QString contact,
	QWidget *parent
) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addSpacing(55);

    usernameDetail = new QLabel(username, this);
    mainLayout->addWidget(usernameDetail);
    usernameDetail->setMinimumSize(50, 30);

    batchDetail = new QLabel(batch, this);
    mainLayout->addWidget(batchDetail);
    batchDetail->setMinimumSize(50, 30);

    emailDetail = new QLabel(email, this);
    mainLayout->addWidget(emailDetail);
    emailDetail->setMinimumSize(50, 30);

    contactDetail = new QLabel(contact, this);
    mainLayout->addWidget(contactDetail);
    contactDetail->setMinimumSize(50, 30);
    
    setLayout(mainLayout);
}
