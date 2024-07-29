#pragma once
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>

#include "httplib.h"


class PackEvent: public QWidget {
	public :
	explicit PackEvent(
		QWidget *parent,
		httplib::Client* client,
		const std::string& flyer_id,
		QString organizer,
		QString event_name
	);
	QPushButton* getDetailsButton();

	private:
	QPushButton *see_details_btn;
};
