#include "Application/Application.h"
#include "Application/Page.h"
#include "Pages/LoginPage.h"
#include "Pages/SignupPage.h"
#include "Pages/DashBoard.h"

#include "Application/Application.cpp"
#include "Pages/DashBoard.cpp"
#include "Pages/LoginPage.cpp"
#include "Pages/SignupPage.cpp"
#include "Widgets/PasswordLineEdit.cpp"
#include "Widgets/dashBoardNavBar.cpp"
#include "Widgets/emailValidation.cpp"
#include "Widgets/ProfilePage.cpp"
#include "Widgets/PostPage.cpp"
#include "Widgets/OngoingEvents.cpp"
#include "Widgets/UpcomingEvents.cpp"
class App : public Application {
public:
	void onAttach() {
		// Here the parameter is the name of the class
		// The same name will be used while switching the page
		addPage<LoginPage>("LoginPage");
		addPage<SignupPage>("SignupPage");
		addPage<DashBoard>("DashBoard");

		switchPage("DashBoard");
		// switchPage("SignupPage");
		// switchPage("LoginPage");


	}
};

int main(int argc, char** argv) {
	App app;
	int s = app.run("KUvent", argc, argv);
	return s;
}

