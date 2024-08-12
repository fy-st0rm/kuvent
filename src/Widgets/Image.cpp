#include "Image.h"

Image::Image(
	httplib::Client* client,
	const std::string& flyer_id,
	QWidget* parent
) : QWidget(parent), m_label(new QLabel) {

    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addWidget(m_label, 0, Qt::AlignCenter);
    setLayout(hLayout);

    QPixmap placeholder = QPixmap(m_placeholder);

    // Set the label to scale its contents
    m_label->setScaledContents(true);
    m_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    // Initially set a placeholder image
    updateImage(placeholder);


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
    updateImage(pixmap);
}


void Image::updateImage(const QPixmap& pixmap) {
    // Calculate the aspect ratio of the image
    double aspectRatio = static_cast<double>(pixmap.width()) / pixmap.height();
	//static_cast converts to <type> value at compile time , more safe than explicit cast
    int maxWidth = 310;
    int maxHeight = 300;
    int width = maxWidth;
    int height = static_cast<int>(width / aspectRatio);

    if (height > maxHeight) {
        height = maxHeight;
        width = static_cast<int>(height * aspectRatio);
    }

    m_label->setFixedSize(width, height);
    m_label->setPixmap(pixmap);
}

void Image::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);
    updateImage(m_label->pixmap(Qt::ReturnByValue));
}