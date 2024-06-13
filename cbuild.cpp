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
	copy_file("bin/libcrypto-3-x64.dll", "vendor/openssl/lib/win/libcrypto-3-x64.dll");
	copy_file("bin/libssl-3-x64.dll", "vendor/openssl/lib/win/libssl-3-x64.dll");
#elif defined(__linux__)
	copy_file("bin/libcrypto.so.3", "vendor/openssl/lib/linux/libcrypto.so.3");
	copy_file("bin/libssl.so.3", "vendor/openssl/lib/linux/libssl.so.3");
#endif
}

void compile_vendor() {
	CBuild cbuild("gcc");
	cbuild
		.inc_paths({
			"vendor/sqlite3"
		})
		.src({
			"vendor/sqlite3/sqlite3.c",
		})
		.compile();
}

void build(char** argv) {
	CBuild cbuild("g++");
	cbuild
		.out("bin", "server")
		.flags({
			"-Wl,-rpath='$ORIGIN'", "-std=c++17"
		})
		.inc_paths({
			"vendor/httplib",
			"vendor/openssl/include",
			"vendor/sqlite3",
			"vendor/json",
			"src/"
		})
		.lib_paths({
			"vendor/openssl/lib"
		})
		.libs({
			"ssl",
			"crypto",
		})
		.src({
			"vendor/json/jsoncpp.cpp",
			"src/db/db.cpp",
			"src/routes/registration.cpp",
			"src/main.cpp"
		})
		.objs({
			"vendor/sqlite3/sqlite3.o"
		})
		.build()
		.pop_objs({
			"vendor/sqlite3/sqlite3.o"
		})
		.clean();

	copy_dlls();
	cbuild.run();
}

void init_db(char** argv) {
	CBuild cbuild("g++");
	cbuild
		.out("bin", "db_init")
		.flags({
			"-Wl,-rpath='$ORIGIN'", "-std=c++17"
		})
		.inc_paths({
			"vendor/httplib",
			"vendor/openssl/include",
			"vendor/sqlite3",
			"src/"
		})
		.lib_paths({
			"vendor/openssl/lib"
		})
		.libs({
			"ssl",
			"crypto",
		})
		.src({
			"src/db/db.cpp",
			"src/db/db_init.cpp",
		})
		.objs({
			"vendor/sqlite3/sqlite3.o"
		})
		.build()
		.pop_objs({
			"vendor/sqlite3/sqlite3.o"
		})
		.clean();

	copy_dlls();
	cbuild.run();
}

int main(int argc, char** argv) {
	cbuild_rebuild(argc, argv);

	if (!file_exists("vendor/sqlite3/sqlite3.o")) {
		compile_vendor();
	}

	if (!file_exists("storage/database.db")) {
		std::filesystem::create_directories("storage");
		LOG("Initializing database...");
		init_db(argv);
		LOG("Database initialization completed.");
	}

	build(argv);

	return 0;
}
