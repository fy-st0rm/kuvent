#include "DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "theme.h"


void DashBoard::onAttach() {
	// Changing the stylesheet of the base widget of page
	getBaseWidget()->setStyleSheet("background-color:" + Theme::dashboardbuttonBg);

	// H_dash_layout is the main layout of the page
	H_dash_layout = new QHBoxLayout(this);
	H_dash_layout->setSpacing(0);
	H_dash_layout->setContentsMargins(0, 0, 0, 0);

	// Set the layout of the page to the main layout
	setLayout(H_dash_layout);

	QWidget *leftPanel = new QWidget(this);
	QVBoxLayout *left_layout = new QVBoxLayout(leftPanel);
		leftPanel->setStyleSheet(
			"background-color:" + Theme::dashboardPanel + ";"
			);

		DashBoardNavBar *nav_bar = new DashBoardNavBar(leftPanel);
		left_layout->addLayout(nav_bar);
		
	QWidget *rightPanel = new QWidget(this);
	QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
	rightLayout->setAlignment(Qt::AlignTop);


	H_dash_layout->addWidget(leftPanel, 1);
	H_dash_layout->addWidget(rightPanel, 17);

    stackedWidget = new QStackedWidget(rightPanel);
    rightLayout->addWidget(stackedWidget);

    createPages();

    connect(nav_bar->getOngoingButton(), &QPushButton::clicked, this, [this] () {showPages(0);});
    connect(nav_bar->getProfileButton(), &QPushButton::clicked, this, [this] () {showPages(1);});
    connect(nav_bar->getUpcomingButton(), &QPushButton::clicked, this, [this] () {showPages(2);});
    connect(nav_bar->getPostButton(), &QPushButton::clicked, this, [this] () {showPages(3);});
}

void DashBoard::createPages()
{
    ProfilePage *profilePage = new ProfilePage;
    OngoingEventsPage *ongoingEventsPage = new OngoingEventsPage;
    UpcomingEventsPage *upcomingEventsPage = new UpcomingEventsPage;
    PostPage *postPage = new PostPage;

    stackedWidget->addWidget(ongoingEventsPage);
    stackedWidget->addWidget(profilePage);
    stackedWidget->addWidget(upcomingEventsPage);
    stackedWidget->addWidget(postPage);

}

void DashBoard::showPages(int index)
{
    stackedWidget->setCurrentIndex(index);
}