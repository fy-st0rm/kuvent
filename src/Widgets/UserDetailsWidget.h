#pragma once

#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtCore/QPropertyAnimation>
class UserDetailsWidget: public QWidget{
    public:
    UserDetailsWidget (QWidget *parent = nullptr);

    private:
    QWidget *detailsContainer;
    QVBoxLayout *detailsLayout;

    private slots:
    void toggleDetails(QWidget *detailsContainer);

};