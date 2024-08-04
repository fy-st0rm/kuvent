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

class OngoingEventsPage : public Page {
public:
    void onAttach();
    void onEntry();
    void onExit();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    void generateDetailsPages(const Json::Value& events);
    Json::Value fetchEvents();
    Json::Value filterOngoingEvents(const Json::Value& events);
    void displayOngoingEvents(const Json::Value& ongoingEvents);
    Json::Value fetchFlyers(const std::string& eventId);
    void adjustLayout();

private:
		QLabel* placeholder = nullptr;
		QScrollArea *scrollArea;
		QVBoxLayout *mainLayout;
    QGridLayout *ongoingEventsLayout;
    QWidget *containerWidget;
    PageSwitcher *m_pg_switcher;
    QList<PackEvent*> eventWidgets;
};
