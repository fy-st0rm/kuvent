
#ifndef DASHBOARDNAVBAR_H
#define DASHBOARDNAVBAR_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

class DashBoardNavBar : public QVBoxLayout
{

public:
    explicit DashBoardNavBar(bool isOrganizer , QString user_name, QWidget *parent = nullptr);
    QPushButton *getProfileButton();
    QPushButton *getOngoingButton();
    QPushButton *getUpcomingButton();
    QPushButton *getPostButton();

private slots:
    void resetButtonStyles();

private:
    void createButton(QPushButton *&button,const QString &iconPath);
    QPushButton *profile_button;
    QPushButton *ongoing_button;
    QPushButton *upcoming_button;
    QPushButton *post_button;
};

#endif // DASHBOARDNAVBAR_H