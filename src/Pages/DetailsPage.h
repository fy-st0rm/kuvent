#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPixmap>

#include "Application/Page.h"
#include "Widgets/PackEvent.h"
#include "Pages/DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "Pages/PostPage.h"

class DetailsPage: public Page{
public:
	DetailsPage(const Json::Value& event_data, const std::string& exit_page)
		: m_event_data(event_data), m_exit_page(exit_page)
	{}
	void onAttach();
	void onEntry();

private:
	std::string getFlyerId();

private:
	QLabel *eventName;
	QLabel *venueLocation;
	QLabel *eventDescription;
	QLabel *startDate;
	QLabel *endDate;
	QLabel *venueDescription;
	QVBoxLayout *main_layout;
	QLabel *organizerLabel;
	QLabel *eventFlyer;
	QToolButton *closeButton;

	Json::Value m_event_data;
	std::string m_exit_page;

	private slots:
	void onCloseClick();
};
