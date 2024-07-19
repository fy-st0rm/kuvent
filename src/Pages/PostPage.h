#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtCore/QLine>

#include "Application/Page.h"

class PostPage: public Page {
public:
	void onAttach();

private:
	void addImage();
	void previewPost();
	void submitPost();

	QLabel *flyer_label;
	QVBoxLayout *v_layout;
	QLineEdit *event_name_entry;
	QTextEdit *description_entry;
	QLabel *image_label;
	QPixmap *currentPixmap = nullptr;
};
