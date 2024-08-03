#include "Widgets/UserDetailsWidget.h"

UserDetailsWidget::UserDetailsWidget(QWidget *parent)
    : QWidget(parent) 
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QWidget *container = new QWidget();
    QVBoxLayout *containerLayout = new QVBoxLayout(container);

    QHBoxLayout *hLayout = new QHBoxLayout();
    containerLayout->addLayout(hLayout);

    QLabel *participantName = new QLabel("Bijan", this);
    hLayout->addWidget(participantName);

    QPushButton *dropdownButton = new QPushButton();
    QIcon dropdownIcon("C:/tests/dropdown.png");
    if (dropdownIcon.isNull()) {
        qDebug() << "Error: Icon not loaded. Check the path.";
    } else {
        dropdownButton->setIcon(dropdownIcon);
        dropdownButton->setIconSize(QSize(20, 20));
    }
    hLayout->addSpacing(30);
    hLayout->addWidget(dropdownButton);
    dropdownButton->setStyleSheet("border: none;");

    QWidget *detailsContainer = new QWidget();
    QVBoxLayout *detailsLayout = new QVBoxLayout(detailsContainer);

    QStringList labelTexts = {
        "Contact number : ",
        "Email : ",
        "Program Batch : ",
    };

    for (const QString &text : labelTexts) {
        QLabel *label = new QLabel(text, this);
        detailsLayout->addWidget(label);
    }

    detailsContainer->setVisible(false);
    containerLayout->addWidget(detailsContainer);

    connect(dropdownButton, &QPushButton::clicked, [detailsContainer, this]() {
        toggleDetails(detailsContainer);
    });
    
    hLayout->setAlignment(Qt::AlignLeft);
    mainLayout->addWidget(container);
    setLayout(mainLayout);
}

void UserDetailsWidget::toggleDetails(QWidget *detailsContainer)
{
    bool show = !detailsContainer->isVisible();
    QPropertyAnimation *animation = new QPropertyAnimation(detailsContainer, "maximumHeight");
    animation->setDuration(200);
    if (show) {
        detailsContainer->setVisible(true);
        animation->setStartValue(0);
        animation->setEndValue(detailsContainer->sizeHint().height());
    } else {
        animation->setStartValue(detailsContainer->sizeHint().height());
        animation->setEndValue(0);
        connect(animation, &QPropertyAnimation::finished, [detailsContainer]() {
            detailsContainer->setVisible(false);
        });
    }
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
