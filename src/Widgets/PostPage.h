#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

class PostPage: public QWidget {
    public:
    explicit PostPage(QString user_name,QWidget *parent = nullptr);
};
