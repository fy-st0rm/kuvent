#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtCore/QDate>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QToolButton>
#include <QtGui/QIcon>
#include <QtWidgets/QHBoxLayout>

class LineEditWithCalendar : public QLineEdit
{
    public: 
    explicit LineEditWithCalendar(QWidget *parent = nullptr);
    QString text() const;
    void setText(const QString &text);

    private slots:
    void toggleCalendar();
    void updateTextfromDate(const QDate &date);

    private:
    QToolButton *calendarButton;
    QCalendarWidget *calendarWidget;
};