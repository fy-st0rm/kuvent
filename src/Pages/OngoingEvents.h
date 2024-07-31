#pragma once

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include "Widgets/PackEvent.h"
#include <QtCore/QDebug>

#include "Application/Application.h"
#include "Application/Page.h"
#include "Widgets/PageSwitcher.h"
#include "Pages/DetailsPage.h"
#include "Pages/DashBoard.h"

class OngoingEventsPage : public Page {
public:
	void onAttach();
	void onEntry();
	void onExit();

private:
	void generateDetailsPages(const Json::Value& events);

private:
	QGridLayout *ongoingEventsLayout;
	QWidget *containerWidget;
	PageSwitcher *m_pg_switcher;
};
