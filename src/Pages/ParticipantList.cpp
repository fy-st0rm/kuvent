#include "Pages/ParticipantList.h"

void ParticipantList::onAttach()
{
    scrollArea = new QScrollArea();
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
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);
    containerLayout->setSpacing(10);
    containerLayout->setContentsMargins(10, 10, 10, 10);

    QHBoxLayout *hLayout1 = new QHBoxLayout();
    containerLayout->addLayout(hLayout1);

    QLabel *eventName = new QLabel("Test Event", this);
    eventName->setStyleSheet(
        "font-weight: bold;"
        "font-size: 12pt;"
        );
    hLayout1->addWidget(eventName);

    QHBoxLayout *hLayout2 = new QHBoxLayout();
    containerLayout->addLayout(hLayout2);

    QLabel *organizerName = new QLabel("Bijan", this);
    organizerName->setStyleSheet(
        "font-size: 10pt;"
        );
    hLayout2->addWidget(organizerName);

    containerLayout->addSpacing(50);

    QHBoxLayout *hLayout3 = new QHBoxLayout();
    containerLayout->addLayout(hLayout3);

    hLayout3->addSpacing(40);
    QLabel *usernameLabel = new QLabel("Username", this);
    usernameLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
    hLayout3->addWidget(usernameLabel);

    QLabel *batchLabel = new QLabel("Program Batch", this);
    batchLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
    hLayout3->addWidget(batchLabel);

    QLabel *emailLabel = new QLabel("Email", this);
    emailLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
    hLayout3->addWidget(emailLabel);

    QLabel *contactLabel = new QLabel("Contact No.", this);
    contactLabel->setStyleSheet("font-weight: bold; font-size: 10pt;");
    hLayout3->addWidget(contactLabel);

    scrollArea->setWidget(containerWidget);

    setCentralWidget(scrollArea);

    containerLayout->addStretch();

}