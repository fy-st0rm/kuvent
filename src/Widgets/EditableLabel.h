#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QEvent>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QMouseEvent>
#include <functional>

class EditableLabel : public QWidget 
{
	public:
	explicit EditableLabel(std::function<void(void)> callback, QWidget *parent = nullptr); 
	
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

	std::function<void(void)> apply_callback;

	protected:
	void mousePressEvent(QMouseEvent *event);
	
};

#endif
