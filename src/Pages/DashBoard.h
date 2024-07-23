#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QFrame>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtWidgets/QScrollArea>

#include "Application/Application.h"
#include "Application/Page.h"
#include "Pages/ProfilePage.h"
#include "Pages/OngoingEvents.h"
#include "Pages/PostPage.h"
#include "Pages/UpcomingEvents.h"
#include "Widgets/PageSwitcher.h"
#include "Widgets/dashBoardNavBar.h"
#include "Widgets/ContactNoEntry.h"
#include "Widgets/FacultyEntry.h"
#include "Widgets/LineEditWithCalendar.h"
#include "Pages/DetailsPage.h"


class DashBoard : public Page {
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();
	void onEntry();
	void onExit();

private:
	QHBoxLayout *H_dash_layout;
	DashBoardNavBar *nav_bar;
	PageSwitcher* m_pg_switcher;

	void switchPage(const std::string& name);
	void createPages();
};
