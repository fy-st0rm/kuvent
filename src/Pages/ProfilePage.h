
#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFrame>

#include "Application/Page.h"

class ProfilePage : public Page {
public:
	void onAttach();

private:
	QVBoxLayout *profileLayout;
	QLabel *profile_pic;
};

