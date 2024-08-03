
#ifndef DASHBOARDNAVBAR_H
#define DASHBOARDNAVBAR_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

#include "Application/Application.h"

class DashBoardNavBar : public QVBoxLayout {
public:
	explicit DashBoardNavBar(QWidget *parent = nullptr);

	void onEntry(AccountType account_type);
	void onExit(AccountType account_type);

	QPushButton *getProfileButton();
	QPushButton *getOngoingButton();
	QPushButton *getUpcomingButton();
	QPushButton *getPostButton();
	QPushButton *getMyEventsButton();

private slots:
	void resetButtonStyles();

private:
	void createButton(QPushButton *&button,const QString &iconPath);
	QPushButton *profile_button;
	QPushButton *ongoing_button;
	QPushButton *upcoming_button;
	QPushButton *post_button;
	QPushButton *myEvents_button;
};

#endif // DASHBOARDNAVBAR_H
