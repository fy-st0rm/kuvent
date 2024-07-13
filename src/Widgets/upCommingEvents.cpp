#include "upCommingEvents.h"

UpCommingEvents::UpCommingEvents(QWidget *parent)
    :QVBoxLayout(parent)
{
    QGridLayout *grid_layout = new QGridLayout(parent);
    grid_layout->setRowMinimumHeight(0,400);

        QLabel *label = new QLabel(QString("Hello, World!"));
        label->setStyleSheet("background-color:#FF0000;");
        grid_layout->addWidget(label,0,0);

    this->addLayout(grid_layout);
}