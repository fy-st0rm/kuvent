
#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

#include "Application/Page.h"

class ProfilePage : public Page {
public:
	void onAttach();

private:
	QVBoxLayout *profileLayout;
};

