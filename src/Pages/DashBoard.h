#pragma once

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsDropShadowEffect>

#include "Application/Application.h"
#include "Application/Page.h"

class DashBoard : public Page
{
public:
	// This is a compulsory function to implement.
	// We create all the widgets inside this function
	void onAttach();


private:
    QVBoxLayout *V_dash_layout;
	QLabel *m_Kuvent_logo;
	QHBoxLayout *m_hLayout1;


};