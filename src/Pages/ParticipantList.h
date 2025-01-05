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
    void setupUI();
	void setupHeader();
    void setupLabels();
	void addLabelToLayout(QHBoxLayout *layout, const QString &text);
	void clearParticipantDetails();
	void displayParticipant(const std::string &user_id);
	void displayParticipants();
	bool handleResponseErrors(const httplib::Result &res, const QString &errorTitle);

	void onCloseClick();

private: 
	Json::Value m_event;
	std::vector<MyEventsDetails*> m_details;

	QScrollArea *scrollArea;
	QWidget *containerWidget;
	QVBoxLayout *mainLayout;
	QVBoxLayout *containerLayout;

	QToolButton *closeButton = nullptr;
};
