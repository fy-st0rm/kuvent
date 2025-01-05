
#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFrame>
#include <QtGui/QPixmap>
#include "Widgets/ContactNoEntry.h"
#include <QtWidgets/QMessageBox>
#include "Widgets/FacultyEntry.h"
#include "Widgets/LabelWithButton.h"

#include "Application/Page.h"
#include "Application/Application.h"
#include "json/json.h"
#include "utils.h"
class ProfilePage : public Page {
public:
	void onAttach();
	void onEntry();

private:
	void changeProfileData(const std::string& attrib, const std::string& value);

private:
	AppData app_data;

	QVBoxLayout *v_profileLayout;
	QBoxLayout *h_profileLayout;

	QLabel *profileLabel;
	QLabel *emailEntryLabel;
	QLabel *programBatchEntryLabel;
	ContactNoEntry *contactNoEntryLabel;
	FacultyEntry *facultyEntryLabel;
	QLabel *usernameEntryLabel;
	LabelWithButton *profilePic = nullptr;
};

