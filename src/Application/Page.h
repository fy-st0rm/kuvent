#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>


class Application;

class Page : public QMainWindow {
public:
	Page() {
		m_main_widget = new QWidget;
	}

	~Page() {
		delete m_main_widget;
	}

public:
	virtual void onAttach() = 0;

	inline QWidget* getBaseWidget() {
		return m_main_widget;
	}

	inline void setLayout(QLayout* layout) const {
		m_main_widget->setLayout(layout);
	}

	void setApp(Application* app) {
		this->app = app;
	}

protected:
	Application* app;

private:
	QWidget* m_main_widget;
};
