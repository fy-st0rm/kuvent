#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
using namespace httplib;

int main(void) {
	Server svr;

	svr.Get("/hi", [](const Request & /*req*/, Response &res) {
		res.set_content("Hello World!", "text/plain");
	});

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("0.0.0.0", 8080);
}
