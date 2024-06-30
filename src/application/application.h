#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>

#include "page.h"

class Application {
public:
	~Application();

public:
	virtual void onAttach() = 0;

	template<typename T>
	void addPage(const std::string& name) {

		// Setting up the page
		Page* pg = new T();
		pg->setApp(this);
		pg->onAttach();

		// Pushing the page to stacked widget and storing seperatly
		m_pages.push_back(pg);
		m_curr_idx = m_stacked_widget->addWidget(
			m_pages.back()->getBaseWidget()
		);
		m_page_idxs.insert({
			name, m_curr_idx
		});
	}

	inline QWidget* getBaseWidget() {
		return m_main_widget;
	}

	void switchPage(const std::string& name);
	int run(const std::string& title, int argc, char** argv);

private:
	void init_qt();

private:
	QApplication* m_app;
	QWidget* m_main_widget;
	QVBoxLayout* m_main_layout;
	QStackedWidget* m_stacked_widget;

	std::vector<Page*> m_pages;
	std::unordered_map<std::string, int> m_page_idxs;
	int m_curr_idx = 0;
};
