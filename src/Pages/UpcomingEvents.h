#pragma once

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtCore/QDebug>

#include "Widgets/PackEvent.h"
#include "Application/Page.h"
#include "Application/Application.h"
#include "Widgets/PageSwitcher.h"
#include "Pages/DetailsPage.h"
#include "Pages/DashBoard.h"
    
class UpcomingEventsPage: public Page {
public:
    void onAttach();
    void onEntry();
    void onExit();
protected:
	bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void generateDetailsPages(const Json::Value& events);
    Json::Value fetchEvents();
    Json::Value filterUpcomingEvents(const Json::Value& events);
    void displayUpcomingEvents(const Json::Value& upcomingEvents);
    Json::Value fetchFlyers(const std::string& eventId);
    void adjustLayout();

private:
		QLabel* placeholder = nullptr;
		QVBoxLayout *mainLayout;
		QHBoxLayout *placeholder_layout = nullptr;
    QGridLayout *upcomingEventsLayout;
    QWidget *containerWidget;
    PageSwitcher *m_pg_switcher;
    QList<PackEvent*> eventWidgets;
};
