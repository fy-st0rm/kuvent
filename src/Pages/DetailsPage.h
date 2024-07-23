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
	void onAttach();
	void onEntry() {}

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
};