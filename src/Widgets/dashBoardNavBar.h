
#ifndef DASHBOARDNAVBAR_H
#define DASHBOARDNAVBAR_H

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>

class DashBoardNavBar : public QVBoxLayout
{
public:
    explicit DashBoardNavBar(QWidget *parent = nullptr);

private:
    QPushButton *profile_button;
    QPushButton *ongoing_button;
    QPushButton *upcoming_button;
    QPushButton *post_button;

    void createButton(QPushButton *&button, const QString &iconPath);
};

#endif // DASHBOARDNAVBAR_H