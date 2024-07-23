#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtCore/QLine>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFrame>
#include <QtGui/QScreen>

#include <optional>
#include "Application/Page.h"
#include "Widgets/LineEditWithCalendar.h"

class PostPage : public Page {
public:
	PostPage();
	~PostPage();
	void onAttach();
	void onEntry() {}


private:
	void addEventNameSection();
	void addDateSection();
	void addLocationSection();
	void addFlyerSection();
	void addDescriptionSection();
	void addButtonSection();
	void addImage();
	void clear();
	void submitPost();
	void createPreviewDialog();

	bool postToServer();
	std::optional<Json::Value> uploadFlyers();

	QLabel* flyer_label;
	QVBoxLayout* v_layout;
	QLineEdit* event_name_entry;
	LineEditWithCalendar* start_date_entry;
	LineEditWithCalendar* end_date_entry;
	QLineEdit* location_entry;
	QLineEdit* location_description_entry;
	QTextEdit* description_entry;
	QString flyer_path;
	QDialog* preview_dialog;	


	QString start_date ;
	QString end_date ;
	QString event_name ;
	QString location ;
	QString description ;

};
