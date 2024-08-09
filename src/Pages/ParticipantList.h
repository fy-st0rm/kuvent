#pragma once 

#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

#include "Widgets/PageSwitcher.h"
#include "Pages/MyEventsPage.h"

class ParticipantList : public Page{
    public:
    void onAttach();
    void onEntry();
    void onExit();

    private: 
    QScrollArea *scrollArea;
    QWidget *containerWidget;
    QVBoxLayout *mainLayout;

};