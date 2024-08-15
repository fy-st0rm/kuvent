#include "PackEvent.h"
#include "Pages/DetailsPage.h"

PackEvent::PackEvent(
	QWidget *parent,
	Application* app,
	const std::string& flyer_id,
	QString organizer,
	QString event_name,
	const std::string& event_id,
	bool is_organizer
) : QWidget(parent), m_app(app), m_event_id(event_id) {

	QWidget *event_widget = new QWidget(this);
	QVBoxLayout *event_layout = new QVBoxLayout(event_widget);
	event_widget->setStyleSheet(
		"background-color: #62B6CB;"
		"border-radius: 20px;"
		"min-width: 310px;"
		"min-height: 400px;"
	);
	QHBoxLayout *header_layout = new QHBoxLayout();

		QLabel *event_name_label = new QLabel;
		event_name_label->setText(QString("<span style='color: red;'>🔴</span>  %1").arg(event_name));

		event_name_label->setStyleSheet(
			"QLabel {"
			"  color: #000000;"
			"  font-size: 18px;"
			"  font-weight: bold;"
			"  background-color: transparent;"
			"}"
		);
		header_layout->addWidget(event_name_label, 0, Qt::AlignLeft);

		if(isUserRegistered() && !is_organizer) {
			QLabel *event_joined = new QLabel(QString::fromUtf8("✓"));
			event_joined->setStyleSheet(
				"QLabel {"
				"  color: #00FF00;"
				"  font-size: 18px;"
				"  font-weight: bold;"
				"  background-color: transparent;"
				"}"
			);
			event_joined->setToolTip("Joined Event"); 
			header_layout->addWidget(event_joined, 0, Qt::AlignRight);
		}
	event_layout->addLayout(header_layout);


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
		Image* flyer = new Image(m_app->client, flyer_id);
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

bool PackEvent::isUserRegistered() {
	AppData app_data = m_app->getAppData();

	Json::Value payload;
	Json::StyledWriter writer;
	payload["user_id"] = app_data.id;
	payload["event_id"] = m_event_id;

	httplib::Result res = m_app->client->Post(
		"/is_registered",
		writer.write(payload),
		"application/json"
	);

	// Checking the response
	if (!res) {
		QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
		return false;
	}

	if (res->status != httplib::StatusCode::OK_200) {
		QMessageBox::warning(
			this,
			"Register status fetch error",
			QString::fromStdString(res->body)
		);
		return false;
	}

	// Reading the response
	Json::Value res_data;
	Json::Reader reader;
	reader.parse(res->body, res_data);

	return res_data["registered"].asBool();
}

