#include "DashBoard.h"
#include "PostPage.h"
#include "theme.h"

PostPage::PostPage()
		: Page()
		, preview_dialog(nullptr)
{
}

PostPage::~PostPage()
{
		if (preview_dialog) {
				delete preview_dialog;
		}
}
void PostPage::onAttach()
{
	getBaseWidget()->setStyleSheet(
		"background-color:" + Theme::dashBg + ";"
		"border-radius: 15px;"
	);

		v_layout = new QVBoxLayout(this);
		setLayout(v_layout);


		// Create an Event Text Label
		QHBoxLayout *hLayout1 = new QHBoxLayout();
		v_layout->addLayout(hLayout1);		
		QLabel* create_an_event_label = new QLabel("Create an Event", this);
		create_an_event_label->setStyleSheet(
				"font-family: 'Lalezar';"
				"font-size: 24px;"
				"color:" + Theme::dashText +";"
				"font-weight: bold;"
				);
		hLayout1->addWidget(create_an_event_label, 0, Qt::AlignCenter);

		//Add details of event text Label
		QHBoxLayout *hLayout2 = new QHBoxLayout();
		v_layout->addLayout(hLayout2);
		QLabel* add_details_label = new QLabel("Add details about your event", this);
		add_details_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 13px; font-weight: 500; color: #7C7C7C;");
		hLayout2->addWidget(add_details_label, 0, Qt::AlignCenter);

		//Horizontal line
		QFrame* horizontal_line = new QFrame();
		horizontal_line->setFrameShape(QFrame::HLine);
		horizontal_line->setLineWidth(1);
		horizontal_line->setStyleSheet("color: #000000;");
		v_layout->addWidget(horizontal_line);

		addEventNameSection();
		addDateSection();
		addLocationSection();
		addFlyerSection();
		addDescriptionSection();
		addButtonSection();

}

void PostPage::addEventNameSection()
{
		QHBoxLayout *layout = new QHBoxLayout();
		v_layout->addLayout(layout);
		QLabel* event_name_label = new QLabel("What's the name of your event?", this);
		event_name_label->setAlignment(Qt::AlignCenter);
		event_name_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 15px; font-weight: 600;"
				"color:" + Theme::dashText +";");
		layout->addWidget(event_name_label);

		//Event name text box label
		QHBoxLayout *centerLayout = new QHBoxLayout();
		v_layout->addLayout(centerLayout);
		event_name_entry = new QLineEdit();
		event_name_entry->setPlaceholderText("Event Name*");
		event_name_entry->setFixedWidth(300);
		event_name_entry->setStyleSheet("background: #FFFFFF; "
																		"border-radius: 8px; height: 16px;color:#000000; width: 800px;"
									"padding: 10px;");
		centerLayout->addWidget(event_name_entry, 0, Qt::AlignCenter);
		applyShadow(event_name_entry);
		v_layout->addSpacing(15);
}

void PostPage::addDateSection()
{
		QHBoxLayout *hLayout3 = new QHBoxLayout();
		v_layout->addLayout(hLayout3);
		QLabel* event_date_label = new QLabel("When does the event start and end?", this);
		event_date_label->setAlignment(Qt::AlignCenter);
		event_date_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 16px; font-weight: 600;"
				"color:" + Theme::dashText +";");
		hLayout3->addWidget(event_date_label);

		//Start-End date text box label
		QHBoxLayout* date_layout = new QHBoxLayout();
		v_layout->addLayout(date_layout);
		QHBoxLayout* start_dateLayout = new QHBoxLayout();
		date_layout->addLayout(start_dateLayout);
		date_layout->setAlignment(Qt::AlignHCenter);
		start_dateLayout->setAlignment(Qt::AlignRight);		
		start_date_entry = new LineEditWithCalendar();
		start_date_entry->setFixedWidth(300);
		start_dateLayout->addWidget(start_date_entry);
		start_date_entry->setStyleSheet("background: #FFFFFF; "
																		"border-radius: 8px; color:#000000;"
									"padding: 10px;");

		date_layout->addSpacing(20);

		QHBoxLayout* end_dateLayout = new QHBoxLayout();
		date_layout->addLayout(end_dateLayout);
		end_dateLayout->setAlignment(Qt::AlignLeft);
		end_date_entry = new LineEditWithCalendar();
		end_dateLayout->addWidget(end_date_entry);
		end_date_entry->setFixedWidth(300);
		end_date_entry->setStyleSheet("background: #FFFFFF; "
																		"border-radius: 8px; color:#000000;"
									"padding: 10px;");


		applyShadow(start_date_entry);
		applyShadow(end_date_entry);
		v_layout->addSpacing(15);

}

void PostPage::addLocationSection()
{
		QHBoxLayout *hLayout4 = new QHBoxLayout();
		v_layout->addLayout(hLayout4);
		QLabel* location_label = new QLabel("Where is it located?", this);
		location_label->setAlignment(Qt::AlignCenter);
		location_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 15px; font-weight: 600; "
				"color:" + Theme::dashText +";");
		hLayout4->addWidget(location_label);

		//Location text box label
		QHBoxLayout *hLayout5 = new QHBoxLayout();
		v_layout->addLayout(hLayout5);
		location_entry = new QLineEdit();
		location_entry->setFixedWidth(350);
		location_entry->setPlaceholderText("Venue*");
		location_entry->setStyleSheet("background: #FFFFFF; border-radius: "
																	"8px; height: 16px;color:#000000;"
									"padding: 10px;");
		hLayout5->addWidget(location_entry,0,Qt::AlignCenter);
		applyShadow(location_entry);

		//Location description text box label
		QHBoxLayout *hLayout6 = new QHBoxLayout();
		v_layout->addLayout(hLayout6);
		location_description_entry = new QLineEdit();
		location_description_entry->setFixedWidth(700);
		location_description_entry->setPlaceholderText("Location description");
		location_description_entry->setStyleSheet("background: #FFFFFF;"
																							"border-radius: 8px; height: 16px;color:#000000;"
												"padding: 10px;");
		applyShadow(location_description_entry);
		hLayout6->addWidget(location_description_entry);
		v_layout->addSpacing(15);
}

void PostPage::addFlyerSection()
{
		QHBoxLayout* flyer_layout = new QHBoxLayout();
		flyer_label = new QLabel("Upload the Event Flyer", this);
		flyer_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 14px; font-weight: 600; "
				"color:" + Theme::dashText +";");
		flyer_layout->addWidget(flyer_label, 0, Qt::AlignRight);

		flyer_layout->addSpacing(10);

		QPushButton* flyer_button = new QPushButton("Upload", this);
		applyShadow(flyer_button);
		flyer_button->setStyleSheet(
			"QPushButton { "
				"background: " + Theme::buttonBg + ";"
				"color: #FFFFFF;"
				"border-radius: 8px;"
				"height: 33px;"
				"width: 95px;"
				"font-weight: bold;"
			"}"
			"QPushButton:hover {"
			"  background-color: " + Theme::buttonHover + ";"
			"}"
		);
		flyer_layout->addWidget(flyer_button, 0, Qt::AlignLeft);

		v_layout->addLayout(flyer_layout);
		connect(flyer_button, &QPushButton::clicked, this, &PostPage::addImage);
		v_layout->addSpacing(20);
}


void PostPage::addDescriptionSection()
{
		QHBoxLayout *hLayout7 = new QHBoxLayout();
		v_layout->addLayout(hLayout7);
		QLabel* description_label = new QLabel("Add description of the event", this);
		description_label->setAlignment(Qt::AlignCenter);
		description_label->setStyleSheet(
				"font-family: 'Inter'; font-size: 15px; font-weight: 600; "
				"color:" + Theme::dashText +";");
		hLayout7->addWidget(description_label);

		//Description text box label
		QHBoxLayout *hLayout8 = new QHBoxLayout();
		v_layout->addLayout(hLayout8);
		description_entry = new QTextEdit();
		description_entry->setPlaceholderText("Description of the event");
		description_entry->setStyleSheet("background: #FFFFFF; "
																		 "border-radius: 8px; height: 79px;color:#000000;"
									 "padding: 10px;");
		hLayout8->addWidget(description_entry);
		applyShadow(description_entry);
}

void PostPage::addButtonSection()
{
		QHBoxLayout* button_layout = new QHBoxLayout();

		//Clear and Post buttons
		QPushButton* clear_button = new QPushButton("Clear", this);
		clear_button->setFixedWidth(89);
		applyShadow(clear_button);
		clear_button->setStyleSheet(
			"QPushButton {"
				"background: #FFFFFF;"
				"color: #1E1E1E;"
				"border: 2px solid " + Theme::red + ";"
				"border-radius: 8px; height: 32px; width: 89px;"
				"font-weight: bold;"
			"}"
			"QPushButton:hover {"
			"  background-color: " + Theme::packEventButtonHover + ";"
			"}"
		);
		button_layout->addWidget(clear_button);
		button_layout->addSpacing(20);
		button_layout->setAlignment(Qt::AlignCenter);

		QPushButton* post_button = new QPushButton("Post", this);
		applyShadow(post_button);
		post_button->setFixedWidth(89);
		post_button->setStyleSheet(
			"QPushButton {"
				"background: " + Theme::buttonBg + ";"
				"color: #FFFFFF;"
				"border-radius: 8px; height: 32px; width: 89px;"
				"font-weight: bold;"
			"}"
			"QPushButton:hover {"
			"  background-color: " + Theme::buttonHover + ";"
			"}"
		);
		button_layout->addWidget(post_button);


		v_layout->addLayout(button_layout);

		connect(clear_button, &QPushButton::clicked, this, &PostPage::clear);
		connect(post_button, &QPushButton::clicked, this, &PostPage::submitPost);
}

void PostPage::addImage()
{
		QString filePath
				= QFileDialog::getOpenFileName(this, "Select Image", "", "Image Files (*.png *.jpg *.bmp)");
		if (!filePath.isEmpty()) {
				QFileInfo fileInfo(filePath);
				QString fileName = fileInfo.fileName();
				flyer_label->setText(fileName);
				flyer_path = filePath;
		}
}

void PostPage::clear()
{
		event_name_entry->clear();
		start_date_entry->clear();
		end_date_entry->clear();
		location_description_entry->clear();
		location_entry->clear();
		description_entry->clear();
		flyer_label->setText("event flyer*");
		flyer_path = "";
}

void PostPage::submitPost()
{
	start_date =start_date_entry->text();
	QDate s_date	= QDate::fromString(start_date, "dd-MMMM-yyyy");
	end_date =end_date_entry->text();
	QDate e_date	= QDate::fromString(end_date, "dd-MMMM-yyyy");
	event_name = event_name_entry->text();
	location = location_entry->text();
	description = description_entry->toPlainText();

	if ( event_name.isEmpty() )
		QMessageBox::warning(this, "Fields incomplete", "Please add the event name");
	else if (start_date.isEmpty())
		QMessageBox::warning(this, "Fields incomplete", "Please add starting date");
	else if (end_date.isEmpty())
		QMessageBox::warning(this, "Fields incomplete", "Please add end date");
	else if (location.isEmpty())
		QMessageBox::warning(this, "Fields incomplete", "Please add location");
	else if (flyer_path.isEmpty())
		QMessageBox::warning(this, "Fields incomplete", "Please add a flyer");
	else if (description.isEmpty())
		QMessageBox::warning(this, "Fields incomplete", "Please add description");
	else if (e_date < s_date)
		QMessageBox::warning(this, "Wrong Date", "End date can't be less than starting date");
	else if (e_date == s_date)
	{
		QMessageBox::warning(this, "Wrong Date", "Start and end dates can not be same");
	}
	else
	{
		createPreviewDialog();
		if (preview_dialog->exec() == QDialog::Accepted) {
			if (postToServer()) {
				QMessageBox::information(this, "Success", "Your post has been successfully submitted!");
				clear();

			} else {
				QMessageBox::warning(
					this, "Error", "Failed to submit the post. Please try again later.");
			}
		}

	}
}

void PostPage::createPreviewDialog()
{
		if (preview_dialog) {
				delete preview_dialog;
		}
		preview_dialog = new QDialog(this);
		preview_dialog->setWindowTitle("Post Preview");
		QVBoxLayout* dialog_layout = new QVBoxLayout(preview_dialog);

		QLabel* name_preview = new QLabel("Event Name: " + event_name);
		QLabel* date_preview
				= new QLabel("Date: " + start_date + " to " + end_date);
		QLabel* location_preview = new QLabel("Location: " + location);
		QLabel* description_preview = new QLabel("Description: " + description);

		dialog_layout->addWidget(name_preview);
		dialog_layout->addWidget(date_preview);
		dialog_layout->addWidget(location_preview);
		dialog_layout->addWidget(description_preview);

		if (!flyer_path.isEmpty()) {
				QPixmap flyer_pixmap(flyer_path);
				QLabel* flyer_preview = new QLabel();
				flyer_preview->setPixmap(
						flyer_pixmap.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));
				dialog_layout->addWidget(flyer_preview);
		}

		QPushButton* post_button = new QPushButton("Post", preview_dialog);
		dialog_layout->addWidget(post_button);

		connect(post_button, &QPushButton::clicked, preview_dialog, &QDialog::accept);
}

bool PostPage::postToServer()
{
		auto ids = uploadFlyers();
		if (!ids.has_value()) {
				return false;
		}

		// Gathering data
		std::string event_name = event_name_entry->text().toStdString();
		std::string start_date = start_date_entry->text().toStdString();
		std::string end_date = end_date_entry->text().toStdString();
		std::string venue = location_entry->text().toStdString();
		std::string venue_desc = location_description_entry->text().toStdString();
		std::string desc = description_entry->toPlainText().toStdString();

		// Preparing payload
		AppData app_data = app->getAppData();
		Json::Value payload;
		payload["name"] = event_name;
		payload["organizer"] = app_data.username;
		payload["organizer_id"] = app_data.id;
		payload["start_date"] = start_date;
		payload["end_date"] = end_date;
		payload["venue"] = venue;
		payload["venue_desc"] = venue_desc;
		payload["desc"] = desc;
		payload["flyers"] = ids.value();

		Json::StyledWriter writer;
		std::string payload_str = writer.write(payload);

		// Sending the request to server
		httplib::Result res = app->client->Post("/post_event", payload_str, "application/str");

		// Checking the response
		if (!res) {
				QMessageBox::critical(this, "Connection Error",
						"Cannot connect to the server. Please check your connection and try again later.");
				return false;
		}

		if (res->status != httplib::StatusCode::OK_200) {
				QMessageBox::warning(this, "Login Error", QString::fromStdString(res->body));
				return false;
		}

		return true;
}

std::optional<Json::Value> PostPage::uploadFlyers()
{
		// Read the image data
		std::string path = flyer_path.toStdString();
		std::ifstream file(path, std::ifstream::binary);
		std::stringstream buff;
		buff << file.rdbuf();

		// Extract name and extension
		std::string filename = path.substr(path.find_last_of("/") + 1);
		std::string ext = path.substr(path.find_last_of(".") + 1);

		// Create multipart form data
		httplib::MultipartFormDataItems items = { { filename, buff.str(), filename, "image/" + ext } };

		// Sending the request to the server
		httplib::Result res = app->client->Post("/upload", items);

		// Checking the response
		if (!res) {
				QMessageBox::critical(this, "Connection Error",
						"Cannot connect to the server. Please check your connection and try again later.");
				return std::nullopt;
		}

		if (res->status != httplib::StatusCode::OK_200) {
				QMessageBox::warning(this, "Post Error", QString::fromStdString(res->body));
				return std::nullopt;
		}

		// Extracting ids
		Json::Value response;
		Json::Reader reader;
		reader.parse(res->body, response);

		Json::Value ids = response["ids"];
		return ids;
}

