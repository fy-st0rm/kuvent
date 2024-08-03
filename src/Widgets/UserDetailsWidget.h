#pragma once

#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

class UserDetailsWidget: public QWidget{
    public:
    UserDetailsWidget (QWidget *parent = nullptr);

    private:
    QComboBox *combobox;
    QLabel *detailsLabel;


};