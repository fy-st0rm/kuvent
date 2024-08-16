#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPixmap>

#include "httplib.h"
#include "Application/Page.h"
#include "Widgets/PackEvent.h"
#include "Pages/DashBoard.h"
#include "Widgets/dashBoardNavBar.h"
#include "Pages/PostPage.h"
#include "Widgets/UserDetailsWidget.h"

class DetailsPage: public Page{
public:
	DetailsPage(
		Application* app,
		const Json::Value& event_data,
		const std::string& exit_page
	) : m_app(app), m_event_data(event_data), m_exit_page(exit_page)
	{}
	void onAttach();
	void onEntry();
	void onExit();

private:
	std::string getFlyerId();
	bool isUserRegistered();

private:
	QVBoxLayout *main_layout;
	QVBoxLayout *final_layout;
	QHBoxLayout *registrationLayout;
	QScrollArea *scrollArea;
	QWidget* containerWidget;

	QLabel *eventName;
	QLabel *venueLocation;
	QLabel *eventDescription;
	QLabel *startDate;
	QLabel *endDate;
	QLabel *venueDescription;
	QLabel *organizerLabel;
	QLabel *eventFlyer;

	QToolButton *closeButton = nullptr;
	QPushButton *registerButton = nullptr;
	QPushButton *leaveButton = nullptr;

	Application* m_app;
	Json::Value m_event_data;
	std::string m_exit_page;

private:
    void setupEventHeader();
    void setupOrganizerInfo();
    void setupDateInfo();
    void setupVenueInfo();
    void setupEventDescription();
    void setupFlyer();
    void setupRegistrationButton();

private slots:
	void onCloseClick();
	void onRegisterClick();
	void onLeaveClick();
};
