#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsDropShadowEffect>
#include <QtWidgets/QFrame>
#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtWidgets/QScrollArea>

#include "Application/Application.h"
#include "Application/Page.h"


class DashBoard : public Page
{
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();

private:
	
	QHBoxLayout *H_dash_layout;
	
};