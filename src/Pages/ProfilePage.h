
#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFrame>
#include <QtGui/QPixmap>

#include "Application/Page.h"
#include "Application/Application.h"

class ProfilePage : public Page {
public:
	void onAttach();
	void onEntry();

private:
	QVBoxLayout *v_profileLayout;
	QBoxLayout *h_profileLayout;

	QLabel *profileLabel;
	QLabel *emailEntryLabel;
	QLabel *contactNoEntryLabel;
	QLabel *programBatchEntryLabel;
};

