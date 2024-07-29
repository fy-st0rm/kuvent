#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QEnterEvent>
#include <QtWidgets/QFileDialog>
#include <QtGui/QPixMap>
#include <QtWidgets/QMessageBox>

class LabelWithButton: public QLabel {
    public:
    LabelWithButton(QWidget *parent = nullptr);
    ~LabelWithButton();

    private slots:
    void onUploadClick();

    protected:
    void enterEvent(QEnterEvent *event);
    void leaveEvent(QEvent *event);

    private:
    QPushButton *button;

};