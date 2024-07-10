#include "DashBoard.h"
#include "theme.h"

void DashBoard::onAttach() {
    // Changing the stylesheet of the base widget of page
    getBaseWidget()->setStyleSheet("background-color:" + Theme::dashboardbuttonBg);

    // V_dash_layout is the main layout of the page
    V_dash_layout = new QVBoxLayout(this);

    // IMP: Do not forget to set the layout of the page to the main layout
    setLayout(V_dash_layout);

    // Here goes the DashBoard widget codes...
    //--------------------------------

    QSize window_size = this->size();
    int windowWidth = window_size.width();
    int windowHeight = window_size.height();

    QFrame *left_frame = new QFrame();
    QVBoxLayout *buttons_layout = new QVBoxLayout(left_frame);
	left_frame->setStyleSheet(
        "background-color:" + Theme::dashboardbuttonBg + ";"
        "max-width:" + QString::number(windowWidth * 0.1) + "px;" // 1/8th of window width
        "max-height:" + QString::number(windowHeight * 1.3) + "px;"
    );
	buttons_layout->setAlignment(Qt::AlignLeft);
	left_frame->setFrameStyle(QFrame::NoFrame);

	profile_button = new QPushButton();
	profile_button->setIcon(QIcon("assets/images/user.png"));
	profile_button->setIconSize(QSize(40,30));
	profile_button->setFixedSize(50,50);
	profile_button->setStyleSheet(
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
		"QPushButton:hover {"
		"background-color:" + Theme::dashboardhoverBg + ";"
		"border-radius: 15px;"
		"}"
	);

	ongoing_button = new QPushButton();
	ongoing_button->setIcon(QIcon("assets/images/ongoing.png"));
	ongoing_button->setIconSize(QSize(40,30));
	ongoing_button->setFixedSize(50,50);
	ongoing_button->setStyleSheet(
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
		"QPushButton:hover {"
		"background-color:" + Theme::dashboardhoverBg + ";"
		"border-radius: 15px;"
		"}"
	);

	upcoming_button = new QPushButton();
	upcoming_button->setIcon(QIcon("assets/images/upcoming.png"));
	upcoming_button->setIconSize(QSize(40,30));
	upcoming_button->setFixedSize(50,50);
	upcoming_button->setStyleSheet(
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
		"QPushButton:hover {"
		"background-color:" + Theme::dashboardhoverBg + ";"
		"border-radius: 15px;"
		"}"
	);

	post_button = new QPushButton();
	post_button->setIcon(QIcon("assets/images/plus.png"));
	post_button->setIconSize(QSize(40,30));
	post_button->setFixedSize(50,50);
	post_button->setStyleSheet(
		"QPushButton {"
		"border-radius: 25px;"
		"border: 2px;"
		"background-color:" + Theme::dashboardBg + ";"
		"}"
		"QPushButton:hover {"
		"background-color:" + Theme::dashboardhoverBg + ";"
		"border-radius: 15px;"
		"}"
	);

	buttons_layout->addSpacing(20);
	buttons_layout->addWidget(profile_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	buttons_layout->addSpacing(10);
	buttons_layout->addWidget(ongoing_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	buttons_layout->addSpacing(10);
	buttons_layout->addWidget(upcoming_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	buttons_layout->addSpacing(10);
	buttons_layout->addWidget(post_button, 0, Qt::AlignHCenter | Qt::AlignTop);
	buttons_layout->addStretch();

    QFrame *right_frame = new QFrame();
    QVBoxLayout *info_layout = new QVBoxLayout(right_frame);
	right_frame->setStyleSheet(
        "background-color:" + Theme::dashboardBg + ";"
        "max-width:" + QString::number(windowWidth * 1.1) + "px;" // 7/8th of window width
        "max-height:" + QString::number(windowHeight * 1.3) + "px;"
		"border-radius: 15px;"
    );
	info_layout->setAlignment(Qt::AlignRight);
	right_frame->setFrameStyle(QFrame::StyledPanel);

	QFrame *inner_frame = new QFrame();
	inner_frame->setStyleSheet(
		"background-color:" + Theme::dashboardbuttonBg + ";"
		"border-radius: 10px;"
	);

	int innerFrameWidth = windowWidth - 20;
	int innerFrameHeight = windowHeight - 20;
	inner_frame->setFixedSize(innerFrameWidth,innerFrameHeight);

	QVBoxLayout *inner_layout = new QVBoxLayout();
	inner_layout->addWidget(inner_frame);
	inner_layout->setContentsMargins(20,20,20,20);

	info_layout->addLayout(inner_layout);

	QVBoxLayout *content_layout = new QVBoxLayout(inner_frame);
	QHBoxLayout *host_layout = new QHBoxLayout();
	content_layout->addLayout(host_layout);

	organizer_name = new QLabel();
	organizer_name->setText("helo");
	organizer_name->setStyleSheet(
		"font-size: 16pt;"
	);
	host_layout->addWidget(organizer_name);
	host_layout->setAlignment(Qt::AlignTop);
	host_layout->setContentsMargins(30,20,0,0);

    // Create a horizontal layout to contain the left and right frames
    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    horizontal_layout->addWidget(left_frame);
	horizontal_layout->addSpacing(10);
    horizontal_layout->addWidget(right_frame);


    // Add the horizontal layout to the main vertical layout
    V_dash_layout->addLayout(horizontal_layout);

}
