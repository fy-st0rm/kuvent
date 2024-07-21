#include "LineEditWithCalendar.h"

LineEditWithCalendar::LineEditWithCalendar(QWidget *parent)
    : QWidget(parent) 
{
    lineEdit = new QLineEdit;
    lineEdit->setPlaceholderText("dd-MM-yyyy");
    lineEdit->setReadOnly(true);

    calendarButton = new QToolButton();
    calendarButton->setIcon(QIcon("assets/images/calendar.png"));
    calendarButton->setCursor(Qt::ArrowCursor);
    calendarButton->setStyleSheet(
        "border: none;"
        "padding: 0px;"
    );

    calendarWidget = new QCalendarWidget();
    calendarWidget->setVisible(false);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(lineEdit);
    layout->addWidget(calendarButton);
    layout->setContentsMargins(0,0,0,0);
    layout->addSpacing(0);

    connect(calendarButton, &QToolButton::clicked, [this]() {
        calendarWidget->setVisible(!calendarWidget->isVisible());
    });

    connect(calendarWidget, &QCalendarWidget::clicked, [this](const QDate &date) {
       this->lineEdit->setText(date.toString("dd-MM-yyyy")) ;
       this->lineEdit->setVisible(true);
       this->calendarWidget->setVisible(false);
    });

    setLayout(layout);

}

QString LineEditWithCalendar::text() const
{
    return lineEdit->text();
}

void LineEditWithCalendar::setText(const QString &text)
{
    lineEdit->setText(text);
}


