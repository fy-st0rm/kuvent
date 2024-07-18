#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include <QtWidgets/QStackedWidget>
#include "Application/Page.h"

class PageSwitcher {
public:
	PageSwitcher(Application* app);
	~PageSwitcher();

	inline QStackedWidget* getBaseWidget() {
		return m_stacked_widget;
	}

	template<typename T>
	void addPage(const std::string& name) {

		// Setting up the page
		Page* pg = new T();
		pg->setApp(m_app);
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

	void switchPage(const std::string& name);

private:
	Application* m_app;
	QStackedWidget* m_stacked_widget;

	std::vector<Page*> m_pages;
	std::unordered_map<std::string, int> m_page_idxs;
	int m_curr_idx = 0;
};
