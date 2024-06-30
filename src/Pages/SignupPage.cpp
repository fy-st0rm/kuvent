#include "Application/Application.h"
#include "SignupPage.h"

void SignupPage::onAttach() {
	// Creating main layout of this page
	m_main_layout = new QVBoxLayout;

	// Applying that main layout to the page
	setLayout(m_main_layout);

	// Here lies the ui codes..

	QLabel* label = new QLabel("This is a Signup page");
	QPushButton* button = new QPushButton("Go to login");

	// Adding the callback function to button click
	connect(
		button,
		&QPushButton::pressed,
		this,
		&SignupPage::onClick
	);

	// Setting up the widgets to the main layout
	m_main_layout->addWidget(label);
	m_main_layout->addWidget(button);
}

void SignupPage::onClick() {
	/* Here switchPage function changes the page 
	 * according to the assigned name
	 * (named assigned while doing addPage)
	 */
	app->switchPage("LoginPage");
}
