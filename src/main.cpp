#include "Application/Application.h"
#include "Application/Page.h"
#include "Pages/LoginPage.h"
#include "Pages/SignupPage.h"
#include "Pages/DashBoard.h"

#include "Application/Application.cpp"
#include "Pages/DashBoard.cpp"
#include "Pages/LoginPage.cpp"
#include "Pages/SignupPage.cpp"
#include "Pages/ProfilePage.cpp"
#include "Pages/PostPage.cpp"
#include "Pages/OngoingEvents.cpp"
#include "Pages/UpcomingEvents.cpp"
#include "Pages/DetailsPage.cpp"
#include "Pages/MyEventsPage.cpp"
#include "Pages/ParticipantList.cpp"

#include "Widgets/PageSwitcher.cpp"
#include "Widgets/PasswordLineEdit.cpp"
#include "Widgets/dashBoardNavBar.cpp"
#include "Widgets/emailValidation.cpp"
#include "Widgets/ContactNoEntry.cpp"
#include "Widgets/FacultyEntry.cpp"
#include "Widgets/LineEditWithCalendar.cpp"
#include "Widgets/PackEvent.cpp"
#include "Widgets/LabelWithButton.cpp"
#include "Widgets/Image.cpp"
#include "Widgets/UserDetailsWidget.cpp"
#include "Widgets/MyEventsDetails.cpp"

class App : public Application {
public:
	void onAttach() {
		// Here the parameter is the name of the class
		// The same name will be used while switching the page
		addPage<LoginPage>("LoginPage");
		addPage<SignupPage>("SignupPage");
		addPage<DashBoard>("DashBoard");
		// switchPage("LoginPage");
		switchPage("DashBoard");
	}
};

int main(int argc, char** argv) {
	App app;
	int s = app.run("KUvent", argc, argv);
	return s;
}

