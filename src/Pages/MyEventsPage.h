#pragma once 

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtGui/QPixmap>

#include "Application/Page.h"
#include "Widgets/PackEvent.h"
#include "Pages/DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "Pages/PostPage.h"
#include "Pages/DetailsPage.h"
#include "Pages/ParticipantList.h"
#include "Widgets/UserDetailsWidget.h"

class MyEventsPage : public Page {
public:
	void onAttach();
	void onEntry();
	void onExit();

protected:
	bool eventFilter(QObject *obj, QEvent *event) override;

private:
	void generateDetailsPages(const Json::Value& events);
	Json::Value fetchEvents();
	Json::Value filterMyEvents(const Json::Value& events);
	void displayMyEvents(const Json::Value& myEvents);
	Json::Value fetchFlyers(const std::string& eventId);
	void adjustLayout();
	void deleteEvent(const std::string& event_id);

private:
	QGridLayout *ongoingEventsLayout;
	QWidget *containerWidget;
	PageSwitcher *m_pg_switcher;
	QList<PackEvent*> eventWidgets;
};
