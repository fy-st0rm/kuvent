#include "PackEvent.h"

PackEvent::PackEvent(
	QWidget *parent,
	httplib::Client* client,
	const std::string& flyer_id,
	QString organizer,
	QString event_name,
	bool is_organizer
) : QWidget(parent) {

	QWidget *event_widget = new QWidget(this);
	QVBoxLayout *event_layout = new QVBoxLayout(event_widget);
	event_widget->setStyleSheet(
		"background-color: #62B6CB;"
		"border-radius: 20px;"
		"min-width: 310px;"
		"min-height: 400px;"
	);

	QLabel *event_name_label = new QLabel(QString::fromUtf8("🔴")+event_name);
	event_name_label->setStyleSheet(
		"QLabel {"
		"  color: #000000;"
		"  font-size: 18px;"
		"  font-weight: bold;"
		"  background-color: transparent;"
		"}"
	);
	event_layout->addWidget(event_name_label);

	QLabel *organizer_label = new QLabel(organizer);
	organizer_label->setStyleSheet(
		"QLabel {"
		"  color: #000000;"
		"  font-size: 14px;"
		"  background-color: transparent;"
		"}"
	);
	event_layout->addWidget(organizer_label);

	if (!flyer_id.empty()) {
		QWidget* image_container = new QWidget(event_widget);
		QVBoxLayout* image_container_layout = new QVBoxLayout(image_container);
		image_container ->setFixedSize(300,300);
		image_container->setStyleSheet(
			"background-color: #FFDFD6"
		);
		Image* flyer = new Image(client, flyer_id);
		image_container_layout->addWidget(flyer, 0, Qt::AlignCenter);
		event_layout->addWidget(image_container, 0, Qt::AlignCenter);
	}

	QHBoxLayout *button_layout = new QHBoxLayout();

	see_details_btn = new QPushButton("See Details", this);
	see_details_btn->setStyleSheet(
		"QPushButton {"
		"  background-color: #B3C8CF;"
		"  color: #000000;"
		"  border: none;"
		"  border-radius: 8px;"
		"  font-size: 12px;"
		"  width: 100px;"
		"  height: 25px;"
		"}"
		"QPushButton:hover {"
		"  background-color: #A3B8BF;"
		"}"
	);
	button_layout->addWidget(see_details_btn, 0, Qt::AlignCenter);

	if (is_organizer) {
		delete_btn = new QPushButton("Delete", this);
		delete_btn->setStyleSheet(
			"QPushButton {"
			"  background-color: #B3C8CF;"
			"  color: #000000;"
			"  border: none;"
			"  border-radius: 8px;"
			"  font-size: 12px;"
			"  width: 100px;"
			"  height: 25px;"
			"}"
			"QPushButton:hover {"
			"  background-color: #A3B8BF;"
			"}"
		);
		button_layout->addWidget(delete_btn, 0, Qt::AlignCenter);
	}

	event_layout->addLayout(button_layout);
	event_layout->addStretch();
	setLayout(event_layout);
}

QPushButton *PackEvent::getDetailsButton() {
	return see_details_btn;
}

QPushButton *PackEvent::getDeleteButton() {
	return delete_btn;
}


