#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>

#include "application/application.h"
#include "application/page.h"

class LoginPage : public Page {
public:
	void onAttach() {
		QVBoxLayout* vLayout = new QVBoxLayout();
		QLabel* label = new QLabel("Login");
		QPushButton* button = new QPushButton("Go To Signup");

		connect(
			button,
			&QPushButton::pressed,
			this,
			&LoginPage::onClick
		);

		vLayout->addWidget(label);
		vLayout->addWidget(button);
		setLayout(vLayout);
	}

	void onClick() {
		app->switchPage("SignupPage");
	}
};

class SignupPage : public Page {
public:
	void onAttach() {
		QVBoxLayout* vLayout = new QVBoxLayout();
		QLabel* label = new QLabel("Signup page");
		QPushButton* button = new QPushButton("Go to login");

		connect(
			button,
			&QPushButton::pressed,
			this,
			&SignupPage::onClick
		);

		vLayout->addWidget(label);
		vLayout->addWidget(button);
		setLayout(vLayout);
	}

	void onClick() {
		app->switchPage("LoginPage");
	}
};

class App : public Application {
public:
	void onAttach() {
		addPage<LoginPage>("LoginPage");
		addPage<SignupPage>("SignupPage");
	}
};

int main(int argc, char** argv) {
	App app;
	int s = app.run("KUvent", argc, argv);
	return s;
}

