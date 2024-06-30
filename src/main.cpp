#include "Application/Application.h"
#include "Application/Page.h"
#include "Pages/LoginPage.h"
#include "Pages/SignupPage.h"

class App : public Application {
public:
	void onAttach() {
		// Here the parameter is the name of the class
		// The same name will be used while switching the page
		addPage<LoginPage>("LoginPage");
		addPage<SignupPage>("SignupPage");

		switchPage("LoginPage");
	}
};

int main(int argc, char** argv) {
	App app;
	int s = app.run("KUvent", argc, argv);
	return s;
}

