#include "Image.h"

Image::Image(
	httplib::Client* client,
	const std::string& flyer_id,
	QWidget* parent
) : QWidget(parent), m_label(new QLabel) {

	layout = new QVBoxLayout(this);
	layout->addWidget(m_label);
	setLayout(layout);

	QPixmap placeholder = QPixmap(m_placeholder);

	m_label->setFixedSize(300, 300);
	m_label->setPixmap(placeholder.scaled(
		300, 300,
		Qt::KeepAspectRatio, Qt::SmoothTransformation
	));
	m_label->setStyleSheet(
		"QLabel {"
		"  background-color: transparent;"
		"}"
	);

 // Asynchronously load the actual image
	QFuture<QPixmap> future = QtConcurrent::run([this, client, flyer_id]() -> QPixmap{
		// Fetching the flyer from backend
		httplib::Result res = client->Get("/download/" + flyer_id);

		// Checking the result
		if (!res) {
			QMessageBox::critical(
				this,
				"Connection Error",
				"Cannot connect to the server. Please check your connection and try again later."
			);
			return QPixmap(m_placeholder);
		}

		if (res->status != httplib::StatusCode::OK_200) {
			QMessageBox::warning(
				this,
				"Flyer Fetch Error",
				QString::fromStdString(res->body)
			);
			return QPixmap(m_placeholder);
		}

		// Loading the pixmap from image data
		QPixmap pixmap;
		pixmap.loadFromData(
			reinterpret_cast<const uchar*>(res->body.data()),
			res->body.size()
		);
		return pixmap;
	});

	// Update the label once the image is loaded
	m_watcher.setFuture(future);
	connect(
		&m_watcher,
		&QFutureWatcher<QPixmap>::finished,
		this,
		&Image::onImageLoaded
	);
}

void Image::onImageLoaded() {
	QPixmap pixmap = m_watcher.result();
	m_label->setFixedSize(300, 300);
	m_label->setPixmap(pixmap.scaled(
		300, 300,
		Qt::KeepAspectRatio, Qt::SmoothTransformation
	));
	m_label->setStyleSheet(
		"QLabel {"
		"  background-color: transparent;"
		"}"
	);
}
