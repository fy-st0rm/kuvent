#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>

class PostPage: public QWidget {
public:
    explicit PostPage(QString user_name,QWidget *parent = nullptr);

private:
    void addImage();
    void updateImageSize();
    void previewPost();
    void submitPost();
    void resizeEvent(QResizeEvent *event) override;

    QLineEdit *event_name_entry;
    QTextEdit *description_entry;
    QLabel *image_label;
    QPixmap *currentPixmap;
};
