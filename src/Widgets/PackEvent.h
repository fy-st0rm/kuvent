#pragma once
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>


class PackEvent: public QWidget
{
    private:
    QPushButton *see_details_btn;
    
    public :
    explicit PackEvent(QWidget *parent,QString flyer_path,QString organizer ,QString event_name);
    QPushButton *getDetailsButton();
};