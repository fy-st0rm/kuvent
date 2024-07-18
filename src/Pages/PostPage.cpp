#include "PostPage.h"

void PostPage::onAttach() {
	grid_layout = new QGridLayout(this);
	setLayout(grid_layout);

	QLabel *organizer_label = new QLabel("Organizer:", this);
	grid_layout->addWidget(organizer_label, 0, 0);
	QLabel *organizer_name_label = new QLabel(user_name, this);
	grid_layout->addWidget(organizer_name_label, 0, 1);

	QLabel *event_name_label = new QLabel("Event Name:", this);
	grid_layout->addWidget(event_name_label, 1, 0);
	event_name_entry = new QLineEdit(this);
	grid_layout->addWidget(event_name_entry, 1, 1);

	QPushButton *flyer_button = new QPushButton("Add Flyer", this);
	grid_layout->addWidget(flyer_button, 2, 0);
	image_label = new QLabel(this);
	image_label->setAlignment(Qt::AlignCenter);
	image_label->setMinimumSize(300, 300);	// Set a minimum size
	grid_layout->addWidget(image_label, 2, 1);

	QLabel *description_label = new QLabel("Description:", this);
	grid_layout->addWidget(description_label, 3, 0);
	description_entry = new QTextEdit(this);
	grid_layout->addWidget(description_entry, 3, 1);

	QPushButton *preview_button = new QPushButton("Preview", this);
	grid_layout->addWidget(preview_button, 4, 0);
	QPushButton *post_button = new QPushButton("Post", this);
	grid_layout->addWidget(post_button, 4, 1);

	connect(flyer_button, &QPushButton::clicked, this, &PostPage::addImage);
	connect(preview_button, &QPushButton::clicked, this, &PostPage::previewPost);
	connect(post_button, &QPushButton::clicked, this, &PostPage::submitPost);

	// Set stretch factors to make the image and description larger
	grid_layout->setRowStretch(2, 3);  // Image row
	grid_layout->setRowStretch(3, 2);  // Description row
}

void PostPage::addImage() {
	QString filePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.bmp)");
	if (!filePath.isEmpty())
	{
		currentPixmap = new QPixmap(filePath);
		updateImageSize();
	}
}

void PostPage::updateImageSize() {
	if (currentPixmap) {
		QSize labelSize = image_label->size();
		image_label->setPixmap(currentPixmap->scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	}
}

void PostPage::resizeEvent(QResizeEvent *event) {
	updateImageSize();
}

void PostPage::previewPost() {
	// Implement preview functionality
}

void PostPage::submitPost() {
	// Implement post submission
}
