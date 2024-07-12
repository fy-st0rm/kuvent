#include "DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "Widgets/dashBoardFeed.h"
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

        /// -----------------------------------------
		// Add content to the right panel
		// QLabel *label = new QLabel("Main Content Area", rightPanel);
		// rightLayout->addWidget(label);
        DashBoardFeed *feed1 = new DashBoardFeed(rightPanel);
        rightLayout->addLayout(feed1);
        //------------------------------------------
        //add more shit here

    H_dash_layout->addWidget(leftPanel, 1);
    H_dash_layout->addWidget(rightPanel, 17);
}
