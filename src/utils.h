#pragma once

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QPixmap>

#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>

static std::time_t dateStringToTimestamp(const std::string& dateStr) {
	std::tm tm = {};
	std::istringstream ss(dateStr);
	#ifdef _WIN32
				ss >> std::get_time(&tm, "%d-%B-%Y"); // Parse string into std::tm
		#else
				ss >> std::get_time(&tm, "%d-%b-%Y"); // Parse string into std::tm
		#endif
	if (ss.fail()) {
		throw std::runtime_error{"failed to parse time string"};
	}
	std::time_t timestamp = std::mktime(&tm); // Convert std::tm to std::time_t
	return timestamp;
}

static QPixmap createCircularPixmap(const QPixmap& pixmap) {
	int size = std::min(pixmap.width(), pixmap.height());

	// Create a square pixmap with the same width and height
	QPixmap squarePixmap(size, size);
	squarePixmap.fill(Qt::transparent);  // Ensure background is transparent

	// Use QPainter to draw the circular image
	QPainter painter(&squarePixmap);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::SmoothPixmapTransform);

	QPainterPath path;
	path.addEllipse(0, 0, size, size);	// Draw a circle
	painter.setClipPath(path);
	painter.drawPixmap(0, 0, pixmap);  // Draw the original pixmap within the circle

	return squarePixmap;
}

static void applyShadow(QWidget *widget) {
	QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
	shadow->setBlurRadius(5);
	shadow->setColor(QColor(Theme::dropshadow));
	
	if (qobject_cast<QLineEdit*>(widget)) 
		shadow->setOffset(QPointF(2, 2)); 
	else if (qobject_cast<QPushButton*>(widget)) 
		shadow->setOffset(QPointF(1, 1)); 
	else if (qobject_cast<QComboBox*>(widget)) 
		shadow->setOffset(QPointF(1, 1));  
	else if (qobject_cast<QTextEdit*>(widget)) 
		shadow->setOffset(QPointF(1, 1)); 
	else
		shadow->setOffset(QPointF(4, 4)); 
	
	widget->setGraphicsEffect(shadow);
}

