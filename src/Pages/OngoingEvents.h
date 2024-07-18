#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "Application/Page.h"

class OngoingEventsPage : public Page {
public:
	void onAttach();

private:
	QVBoxLayout *ongoingEventsLayout;
};
