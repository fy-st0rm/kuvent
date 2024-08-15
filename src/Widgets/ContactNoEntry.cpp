#include "ContactNoEntry.h"
#include "utils.h"

ContactNoEntry::ContactNoEntry(std::function<void(void)> callback, QWidget *parent) 
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
		applyShadow(editButton);
		editButton->setStyleSheet(
			"QPushButton {"
				"color: white;"
				"background-color: " + Theme::buttonBg + ";"
				"border-radius: 5px;"
			"}"
			"QPushButton:hover {"
				"background-color: " + Theme::buttonHover + ";"
			"}"
		);
    editButton->setFixedSize(80, 30);

    applyButton = new QPushButton("Apply");
		applyShadow(applyButton);
		applyButton->setStyleSheet(
			"QPushButton {"
				"color: white;"
				"background-color: " + Theme::buttonBg + ";"
				"border-radius: 5px;"
			"}"
			"QPushButton:hover {"
				"background-color: " + Theme::buttonHover + ";"
			"}"
		);
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

    connect(applyButton, &QPushButton::clicked, [this]()
    {
        onApplyClick();
    });

    connect(lineEdit, &QLineEdit::returnPressed, [this](){
        finishEditing();
    });

    connect(lineEdit, &QLineEdit::textChanged, [this]()
    {
        updateLineEdit();
    });

}

void ContactNoEntry::setText(const QString &text) {
    label->setText(text);
    lineEdit->setText(text);
}

QString ContactNoEntry::text() const {
    return label->text();
}

void ContactNoEntry::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && !isEditing) {
        startEditing();
    }
    QWidget::mousePressEvent(event);
}

void ContactNoEntry::startEditing() {
    label->setVisible(false);
    lineEdit->setVisible(true);
    editButton->setVisible(false);
    applyButton->setVisible(true);
    lineEdit->setFocus();
    isEditing = true;
}

void ContactNoEntry::finishEditing() {
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

bool ContactNoEntry::containsOnlyIntegers(const QString &number)
{
    QRegularExpression regex("^\\d{10}$");
    return regex.match(number).hasMatch();
}   

void ContactNoEntry::updateLineEdit()
{
    QString number = lineEdit->text();

    if (containsOnlyIntegers(number)){
        lineEdit->setStyleSheet(
            "border: 2px solid green;"
        );
    }

    else
    {
        lineEdit->setStyleSheet(
            "border: 2px solid red;"
        );
    }
}

void ContactNoEntry::onApplyClick()
{
    QString number = lineEdit->text();
    if(containsOnlyIntegers(number))
    {
        finishEditing();
    }

    else{
        QMessageBox::warning(this, "Error", "Please enter a valid contact number");
    }
}
