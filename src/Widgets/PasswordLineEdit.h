#pragma once

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QHBoxLayout>
#include "theme.h"


class PasswordLineEdit : public QLineEdit
{

public:
    explicit PasswordLineEdit(QWidget *parent = nullptr);

private slots:
    void togglePasswordVisibility();

private:
    QToolButton *eyeButton;
    bool passwordVisible;
};