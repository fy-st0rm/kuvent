#pragma once 

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class MyEventsDetails : public QWidget {
    
    public:
    MyEventsDetails (QWidget *parent = nullptr);
    
    private:
    QLabel *usernameDetail;
    QLabel *batchDetail;
    QLabel *contactDetail;
    QLabel *emailDetail;
};