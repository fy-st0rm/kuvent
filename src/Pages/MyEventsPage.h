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

class MyEventsPage : public Page {
public:
    void onAttach();
    

private:
    QGridLayout *myEventsLayout;
    QWidget *containerWidget;

};