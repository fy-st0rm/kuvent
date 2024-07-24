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
        "QScrollBar::add-line:vertical {"  // Fixed typo: 'verical' to 'vertical'
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

    QWidget *containerWidget = new QWidget();

    ongoingEventsLayout = new QGridLayout(containerWidget);
    for (int i = 0 ; i < 5; i++)
    {  
        for (int j = 0 ; j < 3; j++)
        {
            QString event_name = "KUGameJam";
            QString organizer = "KUCC";
            QString flyer_path = "assets/images/gameJam.png";
            PackEvent* event = new PackEvent(containerWidget, flyer_path, organizer, event_name);
            ongoingEventsLayout->addWidget(event, i, j, Qt::AlignTop);
            
            // Connect the details button of each event
            connect(event->getDetailsButton(), &QPushButton::clicked, this, [this, event]() {
                // Handle the details button click here
                // For example, you might want to open a details page:
                // openDetailsPage(event);
            });
        }
    }

    containerWidget->setLayout(ongoingEventsLayout);

    scrollArea->setWidget(containerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea); 
    
    setLayout(mainLayout);
}