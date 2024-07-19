#include "PostPage.h"

void PostPage::onAttach() {
	getBaseWidget()->setStyleSheet("background-color:#000000");
	v_layout = new QVBoxLayout(this);
	setLayout(v_layout);

	QLabel *create_an_event_label = new QLabel("Create an event", this);
	create_an_event_label->setAlignment(Qt::AlignCenter);
	v_layout->addWidget(create_an_event_label, 1, Qt::AlignCenter);

	QLabel *add_details_label = new QLabel("add details about your event", this);
	add_details_label->setAlignment(Qt::AlignCenter);
	v_layout->addWidget(add_details_label, 1, Qt::AlignCenter);

	QFrame* horizontalLine = new QFrame();
	horizontalLine->setFrameShape(QFrame::HLine);
	horizontalLine->setFrameShadow(QFrame::Sunken);
	v_layout->addWidget(horizontalLine);


	QLabel *event_name_label = new QLabel("What is the name of your event?", this);
	event_name_label->setAlignment(Qt::AlignCenter);
	v_layout->addWidget(event_name_label, 1, Qt::AlignCenter);

	QLineEdit *event_name_entry = new QLineEdit();
	event_name_entry->setPlaceholderText("Event Name*");
	v_layout->addWidget(event_name_entry);

	QLabel *event_date_label = new QLabel("When does the event start and end?", this);
	event_date_label->setAlignment(Qt::AlignCenter);
	v_layout->addWidget(event_date_label, 1, Qt::AlignCenter);

	QWidget *date_widget= new QWidget(this);
	QHBoxLayout *date_layout  = new QHBoxLayout(date_widget);
		QWidget *start_date_widget = new QWidget(date_widget);
		QVBoxLayout *start_date_layout = new QVBoxLayout(start_date_widget);
			QLabel *start_date_label = new QLabel("Starting Date", start_date_widget);
			start_date_layout->addWidget(start_date_label);

			QLineEdit *start_date_entry = new QLineEdit();
			start_date_entry->setPlaceholderText("mm/dd/yy*");
			start_date_layout->addWidget(start_date_entry);
		date_layout->addWidget(start_date_widget);

		QWidget *end_date_widget = new QWidget(date_widget);
		QVBoxLayout *end_date_layout = new QVBoxLayout(end_date_widget);
			QLabel *end_date_label = new QLabel("ending Date", end_date_widget);
			end_date_layout->addWidget(end_date_label);

			QLineEdit *end_date_entry = new QLineEdit();
			end_date_entry->setPlaceholderText("mm/dd/yy*");
			end_date_layout->addWidget(end_date_entry);
		date_layout->addWidget(end_date_widget);
		
			
	v_layout->addWidget(date_widget);



	QLabel *location_label = new QLabel("Where is it located?", this);
	location_label->setAlignment(Qt::AlignCenter);
	v_layout->addWidget(location_label, 1, Qt::AlignCenter);

	QLineEdit *location_entry = new QLineEdit();
	location_entry->setPlaceholderText("Venue*");
	v_layout->addWidget(location_entry);

	QLineEdit *location_description_entry = new QLineEdit();
	location_description_entry->setPlaceholderText("Location Description");
	v_layout->addWidget(location_description_entry);

	QWidget *flyer_widget= new QWidget(this);
	QHBoxLayout *flyer_layout  = new QHBoxLayout(flyer_widget);


		flyer_label = new QLabel("Upload flyer for your event", flyer_widget);
		flyer_layout->addWidget(flyer_label);

		QPushButton *flyer_button = new QPushButton("Add Flyer", flyer_widget);
		flyer_layout->addWidget(flyer_button, 0, Qt::AlignRight);

	v_layout->addWidget(flyer_widget);



	QLabel *description_label = new QLabel("Description:", this);
	v_layout->addWidget(description_label, 3);
	description_entry = new QTextEdit(this);
	v_layout->addWidget(description_entry, 3);

	QWidget *nav_widget= new QWidget(this);
	QHBoxLayout *nav_layout  = new QHBoxLayout(nav_widget);
		QPushButton *exit_button = new QPushButton("Post", nav_widget);
		nav_layout->addWidget(exit_button, 4);
		QPushButton *preview_button = new QPushButton("Preview", nav_widget);
		nav_layout->addWidget(preview_button, 4);
		QPushButton *post_button = new QPushButton("Post", nav_widget);
		nav_layout->addWidget(post_button, 4);
	v_layout->addWidget(nav_widget);

	connect(flyer_button, &QPushButton::clicked, this, &PostPage::addImage);
	connect(preview_button, &QPushButton::clicked, this, &PostPage::previewPost);
	connect(post_button, &QPushButton::clicked, this, &PostPage::submitPost);
}

void PostPage::addImage() {
    QString filePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.bmp)");
    if (!filePath.isEmpty())
    {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        flyer_label->setText(fileName);
    }
}

void PostPage::previewPost() {
	// Implement preview functionality
}

void PostPage::submitPost() {
	// Implement post submission
}
