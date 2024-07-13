#include "PostPage.h"

PostPage::PostPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *postLayout = new QVBoxLayout(this);
    QLabel *postLabel = new QLabel("Post Events Page", this);
    postLayout->addWidget(postLabel);
}

