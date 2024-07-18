#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "Application/Page.h"

class UpcomingEventsPage: public Page {
public:
	void onAttach();

private:
	QVBoxLayout *upcomingEventsLayout;
	QLabel* upcomingEventsLabel;
};
