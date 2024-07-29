#include "Pages/DetailsPage.h"

void DetailsPage::onAttach()
{
    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);
    
    QHBoxLayout *hLayout1 = new QHBoxLayout;
	main_layout->addLayout(hLayout1);
	main_layout->setAlignment(Qt::AlignTop);

    eventName = new QLabel(QString::fromUtf8("🔴")+"KU HackFest");
    eventName->setStyleSheet(
        "font-size: 14pt;"
        "font-weight: bold;"
    );

    closeButton = new QToolButton();
    closeButton->setIcon(QIcon("assets/images/close.png"));
    closeButton->setIconSize(QSize(20,20));
    closeButton->setContentsMargins(0,0,0,0);
    hLayout1->addWidget(eventName, 0, Qt::AlignLeft);
    hLayout1->addWidget(closeButton, 0, Qt::AlignRight);

    connect(closeButton, &QToolButton::clicked, this, &DetailsPage::onCloseClick);
    
    QHBoxLayout *hLayout2 = new QHBoxLayout;
	main_layout->addLayout(hLayout2);
	main_layout->setAlignment(Qt::AlignTop);

    organizerLabel = new QLabel("KUCC");
    hLayout2->addWidget(organizerLabel);
    hLayout2->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout3 = new QHBoxLayout;
    main_layout->addLayout(hLayout3);
    QLabel *date = new QLabel("Date");
    date->setStyleSheet(
        "font-weight: bold;"
    );
    hLayout3->addWidget(date);

    QHBoxLayout *hLayout4 = new QHBoxLayout;
    main_layout->addLayout(hLayout4);
    startDate = new QLabel("2024");
    endDate = new QLabel("2025");

    QString startingDate = startDate->text();
    QString endingDate = endDate->text();

    QLabel *eventPeriod = new QLabel(startingDate + "-" + endingDate);
    hLayout4->addWidget(eventPeriod);

    QHBoxLayout *hLayout5 = new QHBoxLayout;
    main_layout->addLayout(hLayout5);

    QLabel *venue = new QLabel("Venue");
    venue->setStyleSheet(
        "font-weight: bold;"
    );
    hLayout5->addWidget(venue);
    hLayout5->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout6 = new QHBoxLayout;
    main_layout->addLayout(hLayout6);

    venueLocation = new QLabel("Multipurpose Hall");
    hLayout6->addWidget(venueLocation);
    hLayout6->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout7 = new QHBoxLayout;
    main_layout->addLayout(hLayout7);

    venueDescription = new QLabel("Description");
    venueDescription->setStyleSheet(
        "color: #3E7689;"
    );
    hLayout7->addWidget(venueDescription);
    hLayout7->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout8 = new QHBoxLayout;
    main_layout->addLayout(hLayout8);

    QLabel *about = new QLabel("About the event");
    about->setStyleSheet(
        "font-weight: bold;"
    );
    hLayout8->addWidget(about);
    hLayout8->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout9 = new QHBoxLayout;
    main_layout->addLayout(hLayout9);

    eventDescription = new QLabel("Event Description");
    hLayout9->addWidget(eventDescription);
    hLayout9->setAlignment(Qt::AlignLeft);

    QHBoxLayout *hLayout10 = new QHBoxLayout;
    main_layout->addLayout(hLayout10);

    eventFlyer = new QLabel();
    QPixmap flyer("assets/images/gameJam.png");
    eventFlyer->setPixmap(flyer);
    eventFlyer->setFixedSize(400,400);
    eventFlyer->setScaledContents(true);

    hLayout10->addWidget(eventFlyer);
    hLayout10->setAlignment(Qt::AlignLeft);

}

void DetailsPage::onCloseClick()
{
    pg_switcher->switchPage("OngoingEvents");
}