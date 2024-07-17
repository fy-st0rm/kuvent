#include "DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "theme.h"

//[ ] TODO :get this stuff dynamically from backend
bool isOrganizer = true;
QString user_name = "KUCC";

void DashBoard::onAttach() {
<<<<<<< HEAD
    // Set the stylesheet of the base widget using the theme's primary background color
    getBaseWidget()->setStyleSheet("background-color:" + Theme::PrimaryBg);

    // Create a QScrollArea
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Create a QWidget to contain the scrollable contentP
    QWidget *scrollContent = new QWidget(scrollArea);
    scrollArea->setWidget(scrollContent);

    // Create the main layout for the scroll content
    QVBoxLayout *V_dash_layout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(V_dash_layout);

    // Add the scroll area to the DashBoard's main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);

    // Create and configure the logo label
    QLabel *m_Kuvent_logo = new QLabel(scrollContent);
    QPixmap loginlogo("assets/images/KUventpng.png");
    if (!loginlogo.isNull()) {
        m_Kuvent_logo->setPixmap(loginlogo);
        m_Kuvent_logo->setFixedSize(300, 120);
        m_Kuvent_logo->setScaledContents(true);
    } else {
        qWarning() << "Failed to load image: assets/images/KUventpng.png";
    }

    // Create a horizontal layout for the logo and add it to the vertical layout
    QHBoxLayout *m_hLayout1 = new QHBoxLayout();
    m_hLayout1->addWidget(m_Kuvent_logo);
    m_hLayout1->setAlignment(Qt::AlignHCenter);
    V_dash_layout->addLayout(m_hLayout1);
    V_dash_layout->setAlignment(Qt::AlignVCenter);

    // Optional: Add more widgets to demonstrate scrolling
    for (int i = 0; i < 100; ++i) {
        QLabel *exampleLabel = new QLabel("Example Text " + QString::number(i), scrollContent);
        V_dash_layout->addWidget(exampleLabel);
    }
=======
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
		stackedWidget = new QStackedWidget(rightPanel);
		rightLayout->addWidget(stackedWidget);

		createPages();

		connect(nav_bar->getOngoingButton(), &QPushButton::clicked, this, [this] () {showPages(0);});
		connect(nav_bar->getProfileButton(), &QPushButton::clicked, this, [this] () {showPages(1);});
		connect(nav_bar->getUpcomingButton(), &QPushButton::clicked, this, [this] () {showPages(2);});
		if(isOrganizer)
			connect(nav_bar->getPostButton(), &QPushButton::clicked, this, [this] () {showPages(3);});
	
	H_dash_layout->addWidget(rightPanel, 17);

>>>>>>> 7a86ce977432e01d56a697136cfcaf2aff990fd4
}

void DashBoard::createPages()
{
    ProfilePage *profilePage = new ProfilePage;
    OngoingEventsPage *ongoingEventsPage = new OngoingEventsPage;
    UpcomingEventsPage *upcomingEventsPage = new UpcomingEventsPage;
    PostPage *postPage = new PostPage(user_name);

    stackedWidget->addWidget(ongoingEventsPage);
    stackedWidget->addWidget(profilePage);
    stackedWidget->addWidget(upcomingEventsPage);
    if(isOrganizer)
		stackedWidget->addWidget(postPage);

}

void DashBoard::showPages(int index)
{
    stackedWidget->setCurrentIndex(index);
}