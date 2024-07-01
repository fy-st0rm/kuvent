#pragma once

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QHBoxLayout>


class PasswordLineEdit : public QLineEdit
{

public:
    explicit PasswordLineEdit(QWidget *parent = nullptr);

private slots:
    void togglePasswordVisibility();

public:
    QToolButton *eyeButton;
    bool passwordVisible;
};