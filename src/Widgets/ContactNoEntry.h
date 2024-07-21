#pragma once

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QMouseEvent>

class ContactNoEntry : public QWidget 
{
    public:
    explicit ContactNoEntry(QWidget *parent = nullptr); 
    
    void setText(const QString &text);

    QString text() const;


    private: 
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *layout;
    QPushButton *editButton;
    QPushButton *applyButton;

    void startEditing();
    void finishEditing();   
    bool isEditing;

    protected:
    void mousePressEvent(QMouseEvent *event);
    bool containsOnlyIntegers(QString &number);
    void updateLineEdit();
    
};