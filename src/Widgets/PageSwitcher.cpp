#include "PageSwitcher.h"


PageSwitcher::PageSwitcher(Application* app)
	: m_app(app) {
	m_stacked_widget = new QStackedWidget;
}

PageSwitcher::~PageSwitcher() {
}

void PageSwitcher::switchPage(const std::string& name) {
	if (m_page_idxs.find(name) == m_page_idxs.end()) {
		std::cerr << "Cannot find page with name: " << name << std::endl;
		exit(1);
	}

	// Getting the index of the page and switching in stacked widget
	m_curr_idx = m_page_idxs[name];
	m_stacked_widget->setCurrentIndex(m_curr_idx);
}
