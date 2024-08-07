#include "FacultyEntry.h"

FacultyEntry::FacultyEntry(std::function<void(void)> callback, QWidget *parent) 
: QWidget(parent), isEditing(false) , apply_callback(callback)
{
    label = new QLabel(this);
    label->setStyleSheet(
        "font-weight: bold;"
        "font-size: 11pt;"
    );
    label->setFixedSize(270,30);
    
    lineEdit = new QLineEdit(this);
    lineEdit->setVisible(false);
    lineEdit->setFixedSize(270,30);
    lineEdit->setStyleSheet("border-radius: 5px;"
                            "background-color: #F0F0F0;");

    editButton = new QPushButton("Edit");
    editButton->setStyleSheet("color: white; background-color: #7469B6; border-radius: 5px;");
    editButton->setFixedSize(80, 30);

    applyButton = new QPushButton("Apply");
    applyButton->setStyleSheet("color: white; background-color: #7469B6; border-radius: 5px;");
    applyButton->setFixedSize(80, 30);
    applyButton->setVisible(false);

    layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(editButton);
    layout->addWidget(applyButton);
    layout->addStretch();
    setLayout(layout);

    // Connect the button click manually
    connect(editButton, &QPushButton::clicked, [this]() {
        startEditing();
    });

    connect(applyButton, &QPushButton::clicked, [this]() {
        finishEditing();
    });

    connect(lineEdit, &QLineEdit::returnPressed, [this](){
        finishEditing();
    });

}

void FacultyEntry::setText(const QString &text) {
    label->setText(text);
    lineEdit->setText(text);
}

QString FacultyEntry::text() const {
    return label->text();
}

void FacultyEntry::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && !isEditing) {
        startEditing();
    }
    QWidget::mousePressEvent(event);
}

void FacultyEntry::startEditing() {
    label->setVisible(false);
    lineEdit->setVisible(true);
    editButton->setVisible(false);
    applyButton->setVisible(true);
    lineEdit->setFocus();
    isEditing = true;
}

void FacultyEntry::finishEditing() {
    if (isEditing) {
        label->setText(lineEdit->text());
        lineEdit->setVisible(false);
        label->setVisible(true);
        editButton->setVisible(true);
        applyButton->setVisible(false);
        isEditing = false;

        apply_callback();
    }
}