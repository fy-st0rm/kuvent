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
		Application* app,
		const std::string& flyer_id,
		QString organizer,
		QString event_name,
		const std::string& event_id,
		bool is_organizer
	);

	QPushButton* getDetailsButton();
	QPushButton* getDeleteButton();

private:
	bool isUserRegistered();

private:
	Application* m_app;
	std::string m_event_id;
	QPushButton *delete_btn;
	QPushButton *see_details_btn;
};
