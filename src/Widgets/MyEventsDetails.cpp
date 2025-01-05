#include "Widgets/MyEventsDetails.h"

MyEventsDetails::MyEventsDetails(
    QString username,
    QString batch,
    QString email,
    QString contact,
    QWidget *parent
) : QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addSpacing(55);

    usernameDetail = createLabel(username);
    mainLayout->addWidget(usernameDetail, Qt::AlignTop);

    batchDetail = createLabel(batch);
    mainLayout->addWidget(batchDetail, Qt::AlignTop);

    emailDetail = createLabel(email);
    mainLayout->addWidget(emailDetail, Qt::AlignTop);

    contactDetail = createLabel(contact);
    mainLayout->addWidget(contactDetail, Qt::AlignTop);

    setLayout(mainLayout);
}

QLabel* MyEventsDetails::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text, this);
    label->setMinimumSize(50, 30);
    label->setStyleSheet("color: #000000;");
    return label;
}
