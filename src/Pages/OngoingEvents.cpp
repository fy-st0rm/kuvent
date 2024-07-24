#include "OngoingEvents.h"
#include "Widgets/PackEvent.h"
#include "Pages/DetailsPage.h"

void OngoingEventsPage::onAttach() 
{
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet(
        "QScrollArea {"
        "border: none;"
        "}"
        "QScrollBar:vertical {"
        "border: none;"
        "margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "border-radius: 5px;"
        "background: #FFFFFF;"
        "}"
        "QScrollBar::add-line:vertical {"
        "background: none;"
        "height: 0px;"
        "}"
        "QScrollBar::sub-line:vertical {"
        "background: none;"
        "height: 0px;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "background: none;"
        "}"
    );
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QWidget *containerWidget = new QWidget();

    QGridLayout *ongoingEventsLayout = new QGridLayout(containerWidget);
    ongoingEventsLayout->setSpacing(40);
    
    for (int i = 0 ; i < 5; i++)
    {  
        for (int j = 0 ; j < 4; j++)
        {
            QString event_name = "KUGameJam";
            QString organizer = "KUCC";
            QString flyer_path = "assets/images/gameJam.png";
            PackEvent* event = new PackEvent(containerWidget, flyer_path, organizer, event_name);
            ongoingEventsLayout->addWidget(event, i, j, Qt::AlignCenter);
            
            // Connect the details button of each event
            connect(event->getDetailsButton(), &QPushButton::clicked, this, [this, event]() {
                // Handle the details button click here
            });
        }
    }

    scrollArea->setWidget(containerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea); 
    
    setLayout(mainLayout);
}
