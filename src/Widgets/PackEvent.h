#pragma once
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>

#include "Widgets/Image.h"
#include "httplib.h"


class PackEvent: public QWidget {
	public :
	explicit PackEvent(
		QWidget *parent,
		httplib::Client* client,
		const std::string& flyer_id,
		QString organizer,
		QString event_name,
		bool is_organizer
	);

	QPushButton* getDetailsButton();
	QPushButton* getDeleteButton();

	private:
	QPushButton *delete_btn;
	QPushButton *see_details_btn;
};
