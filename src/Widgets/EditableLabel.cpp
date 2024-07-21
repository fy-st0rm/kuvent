#include "EditableLabel.h"

EditableLabel::EditableLabel(std::function<void(void)> callback, QWidget *parent)
: apply_callback(callback), QWidget(parent), isEditing(false) {
    label = new QLabel(this);
    label->setStyleSheet(
        "font-weight: bold;"
        "font-size: 11pt;"
    );
    label->setFixedSize(270,30);
    
    lineEdit = new QLineEdit(this);
    lineEdit->setVisible(false);
    lineEdit->setFixedSize(270,30);

    editButton = new QPushButton("Edit");
    editButton->setStyleSheet("color: red; background-color: white;");
    editButton->setFixedSize(80, 30);

    applyButton = new QPushButton("Apply");
    applyButton->setStyleSheet("color: green; background-color: white;");
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

    connect(lineEdit, &QLineEdit::returnPressed, [this]() {
        finishEditing();
    });
}

void EditableLabel::setText(const QString &text) {
    label->setText(text);
    lineEdit->setText(text);
}

QString EditableLabel::text() const {
    return label->text();
}

void EditableLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && !isEditing) {
        startEditing();
    }
    QWidget::mousePressEvent(event);
}

void EditableLabel::startEditing() {
    label->setVisible(false);
    lineEdit->setVisible(true);
    editButton->setVisible(false);
    applyButton->setVisible(true);
    lineEdit->setFocus();
    isEditing = true;
}

void EditableLabel::finishEditing() {
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
