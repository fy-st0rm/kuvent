#include "PostPage.h"

PostPage::PostPage(QString user_name ,QWidget *parent)
    : QWidget(parent)
{
    // QVBoxLayout *postLayout = new QVBoxLayout(this);
    // QLabel *postLabel = new QLabel(user_name, this);
    // postLayout->addWidget(postLabel);


    // QLabel *event_name_label = new QLabel("Event Name :",this);
    // postLayout-> addWidget(event_name_label);


    QGridLayout *grid_layout = new QGridLayout(this);


    QLabel *event_name_label = new QLabel("Event Name :",this);
    grid_layout-> addWidget(event_name_label,0,0);
    QLineEdit *event_name_entry = new QLineEdit(this);
    grid_layout-> addWidget(event_name_entry,0,1);


    QLabel *flyer_label = new QLabel("Flyer :",this);
    grid_layout-> addWidget(flyer_label,1,0);
    QLineEdit *flyer_entry = new QLineEdit(this);
    grid_layout-> addWidget(flyer_entry,1,1);


    QLabel *description_label = new QLabel("Description:",this);
    grid_layout-> addWidget(description_label,2,0);
    QTextEdit *description_entry = new QTextEdit(this);
    grid_layout-> addWidget(description_entry,2,1);
    QString description_text= description_entry->toPlainText();




}

