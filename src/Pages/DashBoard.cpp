#include "DashBoard.h"
#include "theme.h"


void DashBoard::onAttach() {
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
}
