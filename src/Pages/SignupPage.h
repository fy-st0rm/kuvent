#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

#include "Application/Application.h"
#include "Application/Page.h"

class SignupPage : public Page {
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();

private:
	void onClick();

private:
	QVBoxLayout* m_main_layout;
};
