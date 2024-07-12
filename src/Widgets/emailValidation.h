#pragma once

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QHBoxLayout>


class EmailLineEdit : public QLineEdit
{

public:
    explicit EmailLineEdit(QWidget *parent = nullptr);

private:
    void validateEmail(const QString &text);

private slots:
    bool isEmailValid(const QString &email);

};

