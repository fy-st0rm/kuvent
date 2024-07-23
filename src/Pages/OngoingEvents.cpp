    #include "OngoingEvents.h"

    void OngoingEventsPage::onAttach() 
    {
        row = 0;
        column = 0;

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
            "QScrollBar::add-line:verical {"
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

        QString event_name = "KUGameJam";
        QString organizer = "KUCC";
        QString flyer_path = "assets/images/gameJam.png";

        PackEvent* event = new PackEvent(containerWidget, flyer_path, organizer, event_name);
        ongoingEventsLayout->addWidget(event, row, column, Qt::AlignTop);

        column++;
        if (column >= 2)
        {
            column = 0;
            row++;
        }

        containerWidget->setLayout(ongoingEventsLayout);

        scrollArea->setWidget(containerWidget);

        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(scrollArea);  

        setLayout(mainLayout);
    }