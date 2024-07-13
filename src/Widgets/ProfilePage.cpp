#include "ProfilePage.h"

ProfilePage::ProfilePage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *profileLayout = new QVBoxLayout(this);
    QLabel *profileLabel = new QLabel("Profile Page", this);
    profileLayout->addWidget(profileLabel);
}

