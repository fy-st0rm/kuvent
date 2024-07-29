#include "Widgets/LabelWithButton.h"

LabelWithButton::LabelWithButton(Application* app, QWidget *parent)
	: m_app(app), QLabel(parent), button(new QPushButton(this))
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
	QString filePath = QFileDialog::getOpenFileName(
		this,
		"Select Image", "", "Image Files (*.png *.jpg *.bmp)"
	);

	if (!filePath.isEmpty()) {
		QPixmap pixmap(filePath);
		if(!pixmap.isNull()) {
			this->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

			// Setting the pfp in the server

			// Reading the image file
			std::string path = filePath.toStdString();
			std::ifstream file(path, std::ifstream::binary);
			std::stringstream buff;
			buff << file.rdbuf();

			// Extract name and extension
			std::string filename = path.substr(path.find_last_of("/") + 1);
			std::string ext = path.substr(path.find_last_of(".") + 1);

			// Create multipart form data
			httplib::MultipartFormDataItems items = { 
				{ filename, buff.str(), filename, "image/" + ext }
			};

			// Sending the request to the server
			httplib::Result res = m_app->client->Post("/upload", items);

			// Checking the response
			if (!res) {
					QMessageBox::critical(this, "Connection Error",
							"Cannot connect to the server. Please check your connection and try again later.");
			}

			if (res->status != httplib::StatusCode::OK_200) {
					QMessageBox::warning(this, "Post Error", QString::fromStdString(res->body));
			}

			// Extracting ids
			Json::Value response;
			Json::Reader reader;
			reader.parse(res->body, response);

			// Retriving the pfp id
			Json::Value ids = response["ids"];
			std::string pfp = ids[0].asString();

			// Updating the profile in backend
			AppData app_data = m_app->getAppData();
			Json::Value payload;
			payload["id"] = app_data.id;
			payload["attrib"] = "PFP";
			payload["PFP"] = pfp;

			Json::StyledWriter writer;
			std::string payload_str = writer.write(payload);

			// Sending the request to server
			res = m_app->client->Post(
				"/update_profile",
				payload_str,
				"application/json"
			);

			// Checking the response
			if (!res) {
				QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
				return;
			}

			if (res->status != httplib::StatusCode::OK_200) {
				QMessageBox::warning(
					this,
					"Update error",
					QString::fromStdString(res->body)
				);
				return;
			}

			// Setting the pfp in app data
			app_data.pfp = pfp;
			m_app->setAppData(app_data);
		}
		else {
			QMessageBox::information(this, "Error", "Failed to load image");
		}
	}
}

