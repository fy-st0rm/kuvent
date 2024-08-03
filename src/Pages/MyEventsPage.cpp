#include "Pages/MyEventsPage.h"
#include "Widgets/UserDetailsWidget.h"

void MyEventsPage::onAttach()
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

    containerWidget = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(containerWidget);
    containerLayout->setSpacing(40);

    QLabel *label = new QLabel("Hello", this);
    containerLayout->addWidget(label);

    UserDetailsWidget *userDetails = new UserDetailsWidget();
    containerLayout->addWidget(userDetails, 0, Qt::AlignTop);

    scrollArea->setWidget(containerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
	mainLayout->setAlignment(Qt::AlignTop);
	containerLayout->setAlignment(Qt::AlignTop);
}
