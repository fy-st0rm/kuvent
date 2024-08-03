#include "Pages/MyEventsPage.h"

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

	myEventsLayout = new QGridLayout(containerWidget);
	myEventsLayout->setSpacing(40);
	
	scrollArea->setWidget(containerWidget);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(scrollArea); 
	
	setLayout(mainLayout);

    QLabel *label = new QLabel("Hello", this);
    myEventsLayout->addWidget(label);
}

