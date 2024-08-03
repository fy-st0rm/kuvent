#pragma once 

#include <QtWidgets/QLabel>

#include "Widgets/PageSwitcher.h"
#include "Pages/MyEventsPage.h"

class ParticipantList : public Page{
    public:
    void onAttach();
    void onEntry();
    void onExit();

    private:

};