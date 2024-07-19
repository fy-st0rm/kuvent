#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtCore/QLine>
#include <QtWidgets/QDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFrame>
#include <QtGui/QScreen>

#include "Application/Page.h"

class PostPage : public Page {
public:
    PostPage();
    ~PostPage();
	void onAttach();


private:
    void addEventNameSection();
    void addDateSection();
    void addLocationSection();
    void addFlyerSection();
    void addDescriptionSection();
    void addButtonSection();
    void addImage();
    void exit();
    void submitPost();
    void createPreviewDialog();
    bool postToServer();

    QLabel* flyer_label;
    QVBoxLayout* v_layout;
    QLineEdit* event_name_entry;
    QLineEdit* start_date_entry;
    QLineEdit* end_date_entry;
    QLineEdit* location_entry;
    QLineEdit* location_description_entry;
    QTextEdit* description_entry;
    QString flyer_path;
    QDialog* preview_dialog;

};
