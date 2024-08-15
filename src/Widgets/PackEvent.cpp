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
	event_widget->setStyleSheet(
		"background-color: " + Theme::packEventBg + ";"
		"border-radius: 20px;"
	);

	applyShadow(event_widget);

	QVBoxLayout *event_layout = new QVBoxLayout(event_widget);
	QHBoxLayout *header_layout = new QHBoxLayout();

		QLabel *event_name_label = new QLabel(QString::fromUtf8("🔴")+"  "+event_name);
		event_name_label->setStyleSheet(
			"QLabel {"
			"  color: #000000;"
			"  font-size: 18px;"
			"  font-weight: bold;"
			"  background-color: transparent;"
			"}"
		);
		header_layout->addWidget(event_name_label,1,Qt::AlignLeft);

		if(isUserRegistered() && !is_organizer) {
			QLabel *event_joined = new QLabel(QString::fromUtf8("✓"));
			event_joined->setStyleSheet(
				"QLabel {"
				"  color: #000000;"
				"  font-size: 18px;"
				"  font-weight: bold;"
				"  background-color: transparent;"
				"}"
			);
			event_joined->setToolTip("Joined Evemt");
			header_layout->addWidget(event_joined,1,Qt::AlignRight);
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
		image_container ->setFixedSize(250,250);
		image_container->setStyleSheet(
			"background-color: #00D9D9D9"
		);
		Image* flyer = new Image(m_app->client, flyer_id);
		image_container_layout->addWidget(flyer, 0, Qt::AlignCenter);
		event_layout->addWidget(image_container, 0, Qt::AlignCenter);
	}

	QHBoxLayout *button_layout = new QHBoxLayout();
	button_layout->addStretch();
	button_layout->setSpacing(10);

	see_details_btn = new QPushButton(this);
	applyShadow(see_details_btn);
	see_details_btn->setIcon(QIcon("assets/images/details.png"));
	see_details_btn->setIconSize(QSize(30, 30));
	see_details_btn->setToolTip("See Details");
	see_details_btn->setStyleSheet(
		"QPushButton {"
		"  background-color: " + Theme::packEventButtonBg + ";"
		"  color: #000000;"
		"  border: 2px solid " + Theme::dashboardPanel + ";"
		"  border-radius: 8px;"
		"  font-size: 12px;"
		"  width: 40;"
		"  height: 40;"
		"}"
		"QPushButton:hover {"
		"  background-color: " + Theme::packEventButtonHover + ";"
		"}"
	);
	button_layout->addWidget(see_details_btn, 0, Qt::AlignRight);

	if (is_organizer) {
		delete_btn = new QPushButton(this);
		applyShadow(delete_btn);
		delete_btn->setIcon(QIcon("assets/images/trash.png"));
		delete_btn->setIconSize(QSize(30, 30));
		delete_btn->setToolTip("Delete Event");
		delete_btn->setStyleSheet(
			"QPushButton {"
			"  background-color: " + Theme::packEventButtonBg + ";"
			"  color: #000000;"
			"  border: 2px solid " + Theme::dashboardPanel + ";"
			"  border-radius: 8px;"
			"  font-size: 12px;"
			"  width: 40;"
			"  height: 40;"
			"}"
			"QPushButton:hover {"
			"  background-color: " + Theme::packEventButtonHover + ";"
			"}"
		);
		button_layout->addWidget(delete_btn, 0, Qt::AlignRight);
	}

	event_layout->addLayout(button_layout, Qt::AlignBottom);
	event_layout->addStretch();
	event_widget->setLayout(event_layout);
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

