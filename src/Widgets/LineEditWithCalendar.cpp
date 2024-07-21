#include "LineEditWithCalendar.h"

LineEditWithCalendar::LineEditWithCalendar(QWidget *parent)
    : QLineEdit(parent), calendarWidget(new QCalendarWidget()), calendarButton(new QToolButton)
{
    setPlaceholderText("dd-MM-yyyy");
    setReadOnly(true);
    setStyleSheet(
        "background: #FFFFFF;"
        "border: 1px solid #453C3C;" 
        "border-radius: 8px;"
        "height: 30px;"
        "color:#000000;"
        "padding: 5px;"
    );

    calendarButton->setIcon(QIcon("assets/images/calendar.png"));
    calendarButton->setCursor(Qt::PointingHandCursor);
    calendarButton->setStyleSheet(
        "border: none;"
        "padding: 0px;"
    );
    calendarButton->setToolTip("Calendar");
    calendarButton->setIconSize(QSize(25,25));
    calendarButton->setFixedSize(20,20);

    calendarWidget = new QCalendarWidget();
    calendarWidget->setVisible(false);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(calendarButton, 0, Qt::AlignRight);
    layout->setContentsMargins(0,0,10,0);
    layout->addSpacing(0);

    connect(calendarButton, &QToolButton::clicked, [this]() {
        calendarWidget->setVisible(!calendarWidget->isVisible());
    });

    connect(calendarWidget, &QCalendarWidget::clicked, [this](const QDate &date) {
       setText(date.toString("dd-MM-yyyy")) ;
       setVisible(true);
       this->calendarWidget->setVisible(false);
    });

    setLayout(layout);

}

QString LineEditWithCalendar::text() const
{
    return QLineEdit::text();
}

void LineEditWithCalendar::setText(const QString &text)
{
    QLineEdit::setText(text);
}


