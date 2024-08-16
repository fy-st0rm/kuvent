#include "emailValidation.h"
#include "theme.h"

EmailLineEdit::EmailLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
   connect(this, &QLineEdit::textEdited, this, &EmailLineEdit::validateEmail); 
}

void EmailLineEdit::validateEmail(const QString &text)
{

    if (!isEmailValid(text))
    {
        setStyleSheet(
            "border: 2px solid red;"
            "color: #000000;"
            "background-color: #FAF6E7;"
            "border-radius: 5px;"
            "padding: 5px;"
        );
    }

    else {
        setStyleSheet(
            "color: #000000;"
            "background-color: #FAF6E7;"
            "border-radius: 5px;"
            "padding: 5px;"
        
        );
    }
}

bool EmailLineEdit::isEmailValid(const QString &email)
{ 
    QString requiredSuffix = "@gmail.com";

    if (email.isEmpty())
    {
        return true;
    }

    if(!email.endsWith(requiredSuffix, Qt::CaseSensitive)) 
    {
        return false;
    }

    if (email.length() <= requiredSuffix.length())
    {
        return false;
    }

    QString emailWithoutSuffix = email.left(email.length() - requiredSuffix.length());
    if(emailWithoutSuffix.contains(requiredSuffix, Qt::CaseSensitive) || emailWithoutSuffix.contains(" ") 
       || emailWithoutSuffix.contains(" "))
    {
        return false;
    }

    return true;
}
    