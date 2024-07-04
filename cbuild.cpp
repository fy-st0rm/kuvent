#define CBUILD_IMPLEMENTATION
#include "cbuild.h"

#include <fstream>

void copy_file(const std::string& to, const std::string& from) {
	std::ifstream  src(from, std::ios::binary);
	std::ofstream  dst(to, std::ios::binary);
	dst << src.rdbuf();
	dst.close();

	LOG("Copying file from %s -> %s", from.c_str(), to.c_str());
}

bool file_exists(const std::string& path) {
	std::ifstream f(path);
	return f.good();
}

void copy_dlls() {
#ifdef _WIN32
	std::filesystem::create_directories("bin/platforms");

	copy_file("bin/platforms/qwindows.dll", "vendor/qt/lib/windows/platforms/qwindows.dll");
	copy_file("bin/Qt6Core.dll",            "vendor/qt/lib/windows/Qt6Core.dll");
	copy_file("bin/Qt6Widgets.dll",         "vendor/qt/lib/windows/Qt6Widgets.dll");
	copy_file("bin/Qt6Gui.dll",             "vendor/qt/lib/windows/Qt6Gui.dll");
#elif defined(__linux__)
	copy_file("bin/libQt6Core.so.6",    "vendor/qt/lib/linux/libQt6Core.so.6");
	copy_file("bin/libQt6Widgets.so.6", "vendor/qt/lib/linux/libQt6Widgets.so.6");
	copy_file("bin/libQt6Gui.so.6",     "vendor/qt/lib/linux/libQt6Gui.so.6");
#endif
}

void build(char** argv) {
	CBuild cbuild("g++");
	cbuild
		.out("bin", "app")
		.flags({
			"-Wl,-rpath='$ORIGIN'",
			"-std=c++17",
			"-fPIC",
		})
		.inc_paths({
			"vendor/qt/include",
			"vendor/httplib",
			"vendor/json",
			"src"
		})
#ifdef _WIN32
		.lib_paths({
			"vendor/qt/lib/windows"
		})
#elif defined(__linux__)
		.lib_paths({
			"vendor/qt/lib/linux"
		})
#endif
		.libs({
			"Qt6Widgets",
			"Qt6Core",
			"Qt6Gui",
		})
		.src({
			"vendor/json/jsoncpp.cpp",
			"src/Application/Application.cpp",
			"src/Pages/DashBoard.cpp",
			"src/Pages/LoginPage.cpp",
			"src/Pages/SignupPage.cpp",
			"src/Widgets/PasswordLineEdit.cpp",
			"src/main.cpp"
		})
		.build()
		.clean();

	copy_dlls();
	cbuild.run();
}

int main(int argc, char** argv) {
	cbuild_rebuild(argc, argv);
	build(argv);
	return 0;
}
