#include "DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "theme.h"

//[ ] TODO :get this stuff dynamically from backend
bool isOrganizer = true;
QString user_name = "KUCC";

void DashBoard::onAttach() {
	m_pg_switcher = new PageSwitcher(app);

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

	DashBoardNavBar *nav_bar = new DashBoardNavBar(isOrganizer,user_name,leftPanel);
	left_layout->addLayout(nav_bar);
		
	H_dash_layout->addWidget(leftPanel, 1);

	QWidget *rightPanel = new QWidget(this);
	QVBoxLayout *rightLayout = new QVBoxLayout(rightPanel);
	rightLayout->setAlignment(Qt::AlignTop);
	rightLayout->addWidget(m_pg_switcher->getBaseWidget());

	createPages();

	connect(
		nav_bar->getProfileButton(),
		&QPushButton::clicked, this,
		[this]() {
			switchPage("ProfilePage");
	});
	connect(
		nav_bar->getOngoingButton(),
		&QPushButton::clicked, this,
		[this]() {
			switchPage("OngoingPage");
	});
	connect(
		nav_bar->getUpcomingButton(),
		&QPushButton::clicked, this,
		[this]() {
			switchPage("UpcomingPage");
	});
	if(isOrganizer)
		connect(
			nav_bar->getPostButton(),
			&QPushButton::clicked, this,
			[this]() {
				switchPage("PostPage");
		});
	
	H_dash_layout->addWidget(rightPanel, 17);
}

void DashBoard::createPages() {
	m_pg_switcher->addPage<ProfilePage>("ProfilePage");
	m_pg_switcher->addPage<OngoingEventsPage>("OngoingPage");
	m_pg_switcher->addPage<UpcomingEventsPage>("UpcomingPage");
	m_pg_switcher->addPage<PostPage>("PostPage");
}

void DashBoard::switchPage(const std::string& name) {
	m_pg_switcher->switchPage(name);
}
