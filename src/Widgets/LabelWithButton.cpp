#include "Widgets/LabelWithButton.h"

LabelWithButton::LabelWithButton(QWidget *parent)
    : QLabel(parent), button(new QPushButton(this))
{
    button->hide();
    button->setIcon(QIcon("assets/images/upload.png"));
    button->setIconSize(QSize(25,25));

    button->setStyleSheet(
        "border: none;"
        "background-color: #77FFFFFF;"
    );

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    layout->setContentsMargins(0,0,5,5);
    setLayout(layout);

    connect(button, &QPushButton::clicked, this, &LabelWithButton::onUploadClick);
}

LabelWithButton::~LabelWithButton()
{
}

void LabelWithButton::enterEvent(QEnterEvent *event)
{
    button->show();
    QLabel::enterEvent(event);
}

void LabelWithButton::leaveEvent(QEvent *event)
{
    button->hide();
    QLabel::leaveEvent(event);
}

void LabelWithButton::onUploadClick()
{
    QString filePath
        = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty()) {
        QPixmap pixmap(filePath);
        if(!pixmap.isNull()) 
        {
            this->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        else {
            QMessageBox::information(this, "Error", "Failed to load image");
        }
    }
}

