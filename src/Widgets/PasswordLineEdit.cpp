#include "PasswordLineEdit.h"

PasswordLineEdit::PasswordLineEdit(QWidget *parent) : QLineEdit(parent), passwordVisible(false)
{
    this->setEchoMode(QLineEdit::Password);

    eyeButton = new QToolButton(this);
    eyeButton->setIcon(QIcon("assets/images/eye.png"));
    eyeButton->setIconSize(QSize(25, 25));
    eyeButton->setCursor(Qt::PointingHandCursor);
    eyeButton->setToolTip("Show Password");
    eyeButton->setStyleSheet("border: none; padding: 0px;");
    eyeButton->setFixedSize(20, 20);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(eyeButton, 0, Qt::AlignRight);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 5, 0);
    setLayout(layout);

    connect(eyeButton, &QToolButton::clicked, this, &PasswordLineEdit::togglePasswordVisibility);
}

void PasswordLineEdit::togglePasswordVisibility()
{
    if (passwordVisible)
    {
        this->setEchoMode(QLineEdit::Password);
        eyeButton->setIcon(QIcon("assets/images/eye.png"));
        eyeButton->setToolTip("Show Password");
    }
    else
    {
        this->setEchoMode(QLineEdit::Normal);
        eyeButton->setIcon(QIcon("assets/images/eye2.png"));
        eyeButton->setToolTip("Hide Password");
    }

    passwordVisible = !passwordVisible;

}
