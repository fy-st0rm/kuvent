#pragma once

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QMouseEvent>
#include <functional>
#include <QtWidgets/QMessageBox>
#include <QtCore/QRegularExpression>

#include "theme.h"

class ContactNoEntry : public QWidget 
{
    public:
    explicit ContactNoEntry(std::function<void(void)> callback, QWidget *parent = nullptr); 
    
    void setText(const QString &text);
    QString text() const;

	private: 
	QLabel *label;
	QLineEdit *lineEdit;
	QHBoxLayout *layout;
	QPushButton *editButton;
	QPushButton *applyButton;

	std::function<void(void)> apply_callback;

    void startEditing();
    void finishEditing();   
    bool isEditing;

    protected:
    void mousePressEvent(QMouseEvent *event);
    bool containsOnlyIntegers(const QString &number);
    void updateLineEdit();
    void onApplyClick();
    
};
