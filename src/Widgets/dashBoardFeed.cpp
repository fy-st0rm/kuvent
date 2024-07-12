#include "dashBoardFeed.h"

DashBoardFeed::DashBoardFeed(QWidget *parent)
    :QVBoxLayout(parent)
{
    QGridLayout *grid_layout = new QGridLayout(parent);
    grid_layout->setRowMinimumHeight(0,400);

        QLabel *label = new QLabel(QString("Hello, World!"));
        label->setStyleSheet("background-color:#FF0000;");
        grid_layout->addWidget(label,0,0);

        QLabel *label2 = new QLabel(QString("Hello, World!"));
        label2->setStyleSheet("background-color:#00FF00;");
        grid_layout->addWidget(label2,0,1);

        QLabel *label3 = new QLabel(QString("Hello, World!"));
        label3->setStyleSheet("background-color:#FF0000;");
        grid_layout->addWidget(label3,1,0);

        QLabel *label4 = new QLabel(QString("Hello, World!"));
        label4->setStyleSheet("background-color:#00FF00;");
        grid_layout->addWidget(label4,1,1);

    this->addLayout(grid_layout);
}