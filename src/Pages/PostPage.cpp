#include "PostPage.h"
#include "DashBoard.h"

PostPage::PostPage() : Page(), preview_dialog(nullptr) {}

PostPage::~PostPage() {
    if (preview_dialog) {
        delete preview_dialog;
    }
}
void PostPage::onAttach() {
    setStyleSheet("background-color: #B5B5B5;");
    v_layout = new QVBoxLayout(this);
    setLayout(v_layout);

    QLabel* create_an_event_label = new QLabel("Create an Event", this);
    create_an_event_label->setStyleSheet("font-family: 'Lalezar'; font-size: 24px; color: #FFFFFF;");
    v_layout->addWidget(create_an_event_label, 0, Qt::AlignCenter);

    QLabel* add_details_label = new QLabel("Add details about your event", this);
    add_details_label->setStyleSheet("font-family: 'Inter'; font-size: 13px; font-weight: 600; color: #FFFFFF;");
    v_layout->addWidget(add_details_label, 0, Qt::AlignCenter);

    QFrame* horizontal_line = new QFrame();
    horizontal_line->setFrameShape(QFrame::HLine);
    horizontal_line->setFrameShadow(QFrame::Sunken);
    horizontal_line->setStyleSheet("background-color: #1E1E1E;");
    v_layout->addWidget(horizontal_line);

    addEventNameSection();
    addDateSection();
    addLocationSection();
    addFlyerSection();
    addDescriptionSection();
    addButtonSection();
}

void PostPage::addEventNameSection() {
    QLabel* event_name_label = new QLabel("What's the name of your event?", this);
	event_name_label->setAlignment(Qt::AlignCenter);
    event_name_label->setStyleSheet("font-family: 'Inter'; font-size: 16px; font-weight: 600; color: #FFFFFF;");
    v_layout->addWidget(event_name_label);

    event_name_entry = new QLineEdit();
    event_name_entry->setPlaceholderText("Event Name*");
    event_name_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 34px;color:#000000;");
    v_layout->addWidget(event_name_entry);
}

void PostPage::addDateSection() {
    QLabel* event_date_label = new QLabel("When does the event start and end?", this);
	event_date_label->setAlignment(Qt::AlignCenter);
    event_date_label->setStyleSheet("font-family: 'Inter'; font-size: 16px; font-weight: 600; color: #FFFFFF;");
    v_layout->addWidget(event_date_label);

    QHBoxLayout* date_layout = new QHBoxLayout();

    start_date_entry = new QLineEdit();
    start_date_entry->setPlaceholderText("mm/dd/yyyy");
    start_date_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 36px;color:#000000;");
    date_layout->addWidget(start_date_entry);

    end_date_entry = new QLineEdit();
    end_date_entry->setPlaceholderText("mm/dd/yyyy");
    end_date_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 36px;color:#000000;");
    date_layout->addWidget(end_date_entry);

    v_layout->addLayout(date_layout);
}

void PostPage::addLocationSection() {
    QLabel* location_label = new QLabel("Where is it located?", this);
	location_label->setAlignment(Qt::AlignCenter);
    location_label->setStyleSheet("font-family: 'Inter'; font-size: 16px; font-weight: 600; color: #FFFFFF;");
    v_layout->addWidget(location_label);

    location_entry = new QLineEdit();
    location_entry->setPlaceholderText("Venue*");
    location_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 36px;color:#000000;");
    v_layout->addWidget(location_entry);

    location_description_entry = new QLineEdit();
    location_description_entry->setPlaceholderText("Location description");
    location_description_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 36px;color:#000000;");
    v_layout->addWidget(location_description_entry);
}

void PostPage::addFlyerSection() {
    QHBoxLayout* flyer_layout = new QHBoxLayout();

    flyer_label = new QLabel("event flyer*", this);
    flyer_label->setStyleSheet("font-family: 'Inter'; font-size: 16px; font-weight: 600; color: #FFFFFF;");
    flyer_layout->addWidget(flyer_label,0,Qt::AlignRight);

    QPushButton* flyer_button = new QPushButton("Upload", this);
    flyer_button->setStyleSheet("background: #65558F; color: #FFFFFF; border-radius: 15px; height: 33px; width: 95px;");
    flyer_layout->addWidget(flyer_button, 0, Qt::AlignLeft);

	v_layout->addLayout(flyer_layout);
    connect(flyer_button, &QPushButton::clicked, this, &PostPage::addImage);
}

void PostPage::addDescriptionSection() {
    QLabel* description_label = new QLabel("Description of the event*", this);
	description_label->setAlignment(Qt::AlignCenter);
    description_label->setStyleSheet("font-family: 'Inter'; font-size: 16px; font-weight: 600; color: #FFFFFF;");
    v_layout->addWidget(description_label);

    description_entry = new QTextEdit();
    description_entry->setStyleSheet("background: #FFFFFF; border: 1px solid #453C3C; border-radius: 8px; height: 79px;color:#000000;");
    v_layout->addWidget(description_entry);
}

void PostPage::addButtonSection() {
    QHBoxLayout* button_layout = new QHBoxLayout();

    QPushButton* exit_button = new QPushButton("Exit", this);
    exit_button->setStyleSheet("background: #FFFFFF; color: #1E1E1E; border: 1px solid #FF8585; border-radius: 8px; height: 32px; width: 89px;");
    button_layout->addWidget(exit_button);

    QPushButton* post_button = new QPushButton("Post", this);
    post_button->setStyleSheet("background: #65558F; color: #F5F5F5; border-radius: 8px; height: 32px; width: 89px;");
    button_layout->addWidget(post_button);

    v_layout->addLayout(button_layout);

    connect(exit_button, &QPushButton::clicked, this, &PostPage::exit);
    connect(post_button, &QPushButton::clicked, this, &PostPage::submitPost);
}
void PostPage::addImage() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        flyer_label->setText(fileName);
        flyer_path = filePath;
    }
}

void PostPage::exit() {
    // Implement exit functionality
}

void PostPage::submitPost() {
    createPreviewDialog();
    if (preview_dialog->exec() == QDialog::Accepted) {
        if (postToServer()) {
            QMessageBox::information(this, "Success", "Your post has been successfully submitted!");
        } else {
            QMessageBox::warning(this, "Error", "Failed to submit the post. Please try again later.");
        }
    }
}

void PostPage::createPreviewDialog() {
    if (preview_dialog) {
        delete preview_dialog;
    }
    preview_dialog = new QDialog(this);
    preview_dialog->setWindowTitle("Post Preview");
    QVBoxLayout* dialog_layout = new QVBoxLayout(preview_dialog);

    QLabel* name_preview = new QLabel("Event Name: " + event_name_entry->text());
    QLabel* date_preview = new QLabel("Date: " + start_date_entry->text() + " to " + end_date_entry->text());
    QLabel* location_preview = new QLabel("Location: " + location_entry->text());
    QLabel* description_preview = new QLabel("Description: " + description_entry->toPlainText());

    dialog_layout->addWidget(name_preview);
    dialog_layout->addWidget(date_preview);
    dialog_layout->addWidget(location_preview);
    dialog_layout->addWidget(description_preview);

    if (!flyer_path.isEmpty()) {
        QPixmap flyer_pixmap(flyer_path);
        QLabel* flyer_preview = new QLabel();
        flyer_preview->setPixmap(flyer_pixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        dialog_layout->addWidget(flyer_preview);
    }

    QPushButton* post_button = new QPushButton("Post", preview_dialog);
    dialog_layout->addWidget(post_button);

    connect(post_button, &QPushButton::clicked, preview_dialog, &QDialog::accept);
}

bool PostPage::postToServer() {
    //[] TODO : backend
    return true;
}