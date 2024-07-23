#include "PackEvent.h"

PackEvent::PackEvent(QWidget *parent,QString flyer_path,QString organizer ,QString event_name):
    QWidget(parent)
{   
    QWidget *event_widget = new QWidget(this);
    QVBoxLayout *event_layout = new QVBoxLayout(event_widget);
    event_widget->setStyleSheet(
        "   background-color: #D9D9D9;"
        "   border-radius: 20px;"
        "   min-width: 350px;"
        "   min-height: 30px;"
    );

    QLabel *event_name_label = new QLabel(QString::fromUtf8("🔴")+event_name);
    event_name_label->setStyleSheet(
        "QLabel {"
        "   color: #000000;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "   background-color: transparent;"
        "}"
    );
    event_layout->addWidget(event_name_label);

    QLabel *organizer_label = new QLabel(organizer);
    organizer_label->setStyleSheet(
        "QLabel {"
        "   color: #000000;"
        "   font-size: 14px;"
        "   background-color: transparent;"

        "}"
    );
    event_layout->addWidget(organizer_label);

    if (!flyer_path.isEmpty()) {
        QPixmap flyer_pixmap(flyer_path);
        QLabel* flyer_preview = new QLabel();
        flyer_preview->setFixedSize(300, 300);
        flyer_preview->setPixmap(flyer_pixmap.scaled(300, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        flyer_preview->setAlignment(Qt::AlignCenter);
        flyer_preview->setStyleSheet(
            "QLabel {"
            "   background-color: transparent;"
            "}"
        );
        event_layout->addWidget(flyer_preview);
    }

    see_details_btn = new QPushButton("See Details", this);
    see_details_btn->setStyleSheet(
        "QPushButton {"
        "   background-color: #B3C8CF;"
        "   color: #000000;"
        "   border: none;"
        "   border-radius: 8px;"
        "   font-size: 12px;"
        "   width: 100px;"
        "   height: 25px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #A3B8BF;"
        "}"
    );
    event_layout->addWidget(see_details_btn,0,Qt::AlignCenter);

    setLayout(event_layout);

}

QPushButton *PackEvent::getDetailsButton()
{
    return see_details_btn;
}


