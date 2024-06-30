#include "application.h"

Application::~Application() {
	for (auto p : m_pages) {
		delete p;
	}

	delete m_stacked_widget;
	delete m_main_layout;
	delete m_main_widget;
	delete m_app;
}

void Application::init_qt() {
	m_main_widget = new QWidget;

	m_main_layout = new QVBoxLayout;
	m_stacked_widget = new QStackedWidget;

	m_main_layout->addWidget(m_stacked_widget);
	m_main_widget->setLayout(m_main_layout);
}

void Application::switchPage(const std::string& name) {
	if (m_page_idxs.find(name) == m_page_idxs.end()) {
		std::cerr << "Cannot find page with name: " << name << std::endl;
		exit(1);
	}

	// Getting the index of the page and switching in stacked widget
	m_curr_idx = m_page_idxs[name];
	m_stacked_widget->setCurrentIndex(m_curr_idx);
}

int Application::run(const std::string& title, int argc, char** argv) {
	m_app = new QApplication(argc, argv);
	m_app->setApplicationName(QString::fromStdString(title));

	// Setting up main widgets
	init_qt();

	// Running the startup function of app
	onAttach();

	// Checking if pages were added or not
	if (!m_page_idxs.size()) {
		std::cerr << "No pages were added. Add atleast one page." << std::endl;
		exit(1);
	}

	m_stacked_widget->setCurrentIndex(m_curr_idx);
	m_main_widget->show();
	return m_app->exec();
}
