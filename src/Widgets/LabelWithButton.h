#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QEnterEvent>
#include <QtWidgets/QFileDialog>
#include <QtGui/QPixmap>
#include <QtWidgets/QMessageBox>

#include "Application/Application.h"
#include "utils.h"

class LabelWithButton: public QLabel {
public:
	LabelWithButton(Application* app, QWidget *parent = nullptr);
	~LabelWithButton();

	private slots:
	void onUploadClick();

	protected:
	void enterEvent(QEnterEvent *event);
	void leaveEvent(QEvent *event);

private:
	QPushButton *button;
	Application* m_app;
};
