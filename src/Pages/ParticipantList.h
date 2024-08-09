#pragma once 

#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include <vector>

#include "Widgets/PageSwitcher.h"
#include "Widgets/MyEventsDetails.h"
#include "Pages/MyEventsPage.h"

class ParticipantList : public Page{
public:
	ParticipantList(const Json::Value& event)
		: m_event(event)
	{}

	void onAttach();
	void onEntry();
	void onExit();

private:
	void displayParticipants();

private: 
	Json::Value m_event;
	std::vector<MyEventsDetails*> m_details;

	QScrollArea *scrollArea;
	QWidget *containerWidget;
	QVBoxLayout *mainLayout;
	QVBoxLayout *containerLayout;
};
