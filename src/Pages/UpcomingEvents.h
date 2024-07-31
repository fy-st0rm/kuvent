#pragma once

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include "Widgets/PackEvent.h"
#include <QtCore/QDebug>

#include "Application/Page.h"
#include "Application/Application.h"
#include "Application/Page.h"
#include "Widgets/PageSwitcher.h"
#include "Pages/DetailsPage.h"
#include "Pages/DashBoard.h"

class UpcomingEventsPage: public Page {
public:
	void onAttach();
	void onEntry();
	void onExit();

private:
	void generateDetailsPages(const Json::Value& events);

private:
	QGridLayout *upcomingEventsLayout;
	QWidget *containerWidget;
	PageSwitcher *m_pg_switcher;
};
