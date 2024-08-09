#pragma once 

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>

class MyEventsDetails : public QWidget {
	
public:
	MyEventsDetails (
		QString username,
		QString batch,
		QString email,
		QString contact,
		QWidget *parent = nullptr
	);
	
private:
	QLabel *usernameDetail;
	QLabel *batchDetail;
	QLabel *contactDetail;
	QLabel *emailDetail;
};
