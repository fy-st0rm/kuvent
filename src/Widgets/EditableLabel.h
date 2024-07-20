#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QMouseEvent>

class EditableLabel : public QWidget 
{
    public:
    explicit EditableLabel(QWidget *parent = nullptr); 
    
    void setText(const QString &text);

    QString text() const;


    private: 
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *layout;
    QPushButton *editButton;
    QPushButton *applyButton;

    void onEditPressed();
    void startEditing();
    void finishEditing();   
    bool isEditing;

    protected:
    void mousePressEvent(QMouseEvent *event);
    
};

#endif