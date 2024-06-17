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
	//copy_file("bin/libcrypto-3-x64.dll", "vendor/openssl/lib/win/libcrypto-3-x64.dll");
	//copy_file("bin/libssl-3-x64.dll", "vendor/openssl/lib/win/libssl-3-x64.dll");
#elif defined(__linux__)
	copy_file("bin/libQt5Core.so.5", "vendor/qt/lib/libQt5Core.so.5");
	copy_file("bin/libQt5Widgets.so.5", "vendor/qt/lib/libQt5Widgets.so.5");
	copy_file("bin/libQt5Core.so.5.15.11", "vendor/qt/lib/libQt5Core.so.5.15.11");
	copy_file("bin/libQt5Widgets.so.5.15.11", "vendor/qt/lib/libQt5Widgets.so.5.15.11");
#endif
}

void build(char** argv) {
	CBuild cbuild("g++");
	cbuild
		.out("bin", "app")
		.flags({
			"-Wl,-rpath='$ORIGIN'", "-std=c++17"
		})
		.inc_paths({
			"vendor/qt/include",
			"src"
		})
		.lib_paths({
			"vendor/qt/lib"
		})
		.libs({
			"Qt5Core",
			"Qt5Widgets",
		})
		.src({
			"src/main.cpp"
		})
		.build()
		.clean()
		.run();
}

int main(int argc, char** argv) {
	cbuild_rebuild(argc, argv);
	copy_dlls();
	build(argv);
	return 0;
}
