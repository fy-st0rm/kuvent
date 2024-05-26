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

int main(int argc, char** argv) {
	cbuild_rebuild(argc, argv);

	CBuild cbuild("g++");
	cbuild
		.out("bin", "server")
		.flags({
			"-Wl,-rpath='$ORIGIN'", "-std=c++17"
		})
		.inc_paths({
			"vendor/httplib",
			"vendor/openssl/include",
		})
		.lib_paths({
			"vendor/openssl/lib"
		})
		.libs({
			"ssl",
			"crypto"
		})
		.src({
			"src/main.cpp"
		})
		.build()
		.clean();

#ifdef _WIN32
	copy_file("bin/libcrypto-3-x64.dll", "vendor/openssl/lib/win/libcrypto-3-x64.dll");
	copy_file("bin/libssl-3-x64.dll", "vendor/openssl/lib/win/libssl-3-x64.dll");
#elif defined(__linux__)
	copy_file("bin/libcrypto.so.3", "vendor/openssl/lib/linux/libcrypto.so.3");
	copy_file("bin/libssl.so.3", "vendor/openssl/lib/linux/libssl.so.3");
#endif

	cbuild.run(argv);

	return 0;
}
