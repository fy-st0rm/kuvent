#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QPixmap>
#include <QtCore/QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QtWidgets/QMessageBox>

#include "httplib.h"

class Image : public QWidget {
public:
	explicit Image(
		httplib::Client* client,
		const std::string& flyer_id,
		QWidget* parent = nullptr
	);

private:
	void onImageLoaded();

private:
	QVBoxLayout *layout;
	QLabel* m_label;
	QFutureWatcher<QPixmap> m_watcher;

	QString m_placeholder = "assets/images/placeholder.png";
	QPixmap* placeholder = nullptr;
};

