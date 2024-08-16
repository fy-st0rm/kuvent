#include "Application.h"

Application::~Application() {
	delete m_main_layout;
	delete m_main_widget;
	delete m_app;
}

void Application::init_qt() {
	m_main_widget = new QWidget;

	m_main_layout = new QVBoxLayout;
	m_pg_switcher = new PageSwitcher(this);

	m_main_layout->addWidget(m_pg_switcher->getBaseWidget());
	m_main_layout->setContentsMargins(0, 0, 0, 0);

	m_main_widget->setLayout(m_main_layout);

	m_main_widget->setMinimumSize(800,600);

}

int Application::run(const std::string& title, int argc, char** argv) {
	m_app = new QApplication(argc, argv);
	m_app->setApplicationName(QString::fromStdString(title));
	m_app->setWindowIcon(QIcon("assets/images/KUventfav.png"));

	// Setting up main widgets
	init_qt();

	// Establishing client
	client = new httplib::Client("172.18.100.198", 8080);

	// Running the startup function of app
	onAttach();

	//m_stacked_widget->setCurrentIndex(m_curr_idx);
	m_main_widget->show();
	return m_app->exec();
}
