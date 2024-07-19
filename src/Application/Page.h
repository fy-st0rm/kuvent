#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>


class Application;
class PageSwitcher;

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
	virtual void onEntry() {};
	virtual void onExit() {}

	inline QWidget* getBaseWidget() {
		return m_main_widget;
	}

	inline void setLayout(QLayout* layout) const {
		m_main_widget->setLayout(layout);
	}

	void setApp(Application* app) {
		this->app = app;
	}
	void setPageSwitcher(PageSwitcher* pg_switcher) {
		this->pg_switcher = pg_switcher;
	}

protected:
	Application* app;
	PageSwitcher* pg_switcher;

private:
	QWidget* m_main_widget;
};
