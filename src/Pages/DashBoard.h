#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsDropShadowEffect>
<<<<<<< HEAD
#include <QtWidgets/QScrollArea>
#include <QtGui/QPixmap>
=======
#include <QtWidgets/QFrame>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtWidgets/QScrollArea>
>>>>>>> 7a86ce977432e01d56a697136cfcaf2aff990fd4

#include "Application/Application.h"
#include "Application/Page.h"
#include "Pages/ProfilePage.h"
#include "Pages/OngoingEvents.h"
#include "Pages/PostPage.h"
#include "Pages/UpcomingEvents.h"
#include "Widgets/PageSwitcher.h"


class DashBoard : public Page {
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();

private:
	QHBoxLayout *H_dash_layout;
	// QStackedWidget *stackedWidget;
	PageSwitcher* m_pg_switcher;
	
	void createPages();
	void switchPage(const std::string& name);
};
