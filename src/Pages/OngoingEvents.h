#pragma once

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>

#include "Widgets/PackEvent.h"

#include "Application/Page.h"

class OngoingEventsPage : public Page {
public:
	void onAttach();
	void onEntry() {}

private:
	QGridLayout *ongoingEventsLayout;
	PackEvent *event;
	int row;
	int column;
};
