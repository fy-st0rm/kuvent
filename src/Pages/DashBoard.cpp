#include "DashBoard.h"


void DashBoard::onAttach() {
	// Changing the stylesheet of the base widget of page
	getBaseWidget()->setStyleSheet("background-color: #3C6E71;");

	// V_dash_layout is the main layout of the page
	V_dash_layout = new QVBoxLayout();

	// IMP: Do not forget to set the layout of the page to the main layout
	setLayout(V_dash_layout);

	// Here goes the DashBoard widget codes...





//--------------------------------
    m_Kuvent_logo = new QLabel(this);
	QPixmap loginlogo("assets/images/KUventpng.png");
	m_Kuvent_logo->setPixmap(loginlogo);
	m_Kuvent_logo->setFixedSize(300,120);
	m_Kuvent_logo->setScaledContents(true);
	
	//horizontal layout for m_Kuvent_logo
	QHBoxLayout *m_hLayout1 = new QHBoxLayout();
	V_dash_layout->addLayout(m_hLayout1);
	V_dash_layout->addSpacing(1);
	V_dash_layout->setAlignment(Qt::AlignVCenter);
	m_hLayout1->addWidget(m_Kuvent_logo);
	m_hLayout1->setAlignment(Qt::AlignHCenter);

// only for tests , delete this shite if you got something that works
//-------------------------------
}
