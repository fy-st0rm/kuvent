#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
using namespace httplib;

#include "db/db.h"
#include "routes/registration.h"

int main(void) {
	Server svr;

	svr.set_logger([](const Request& req, const Response& res) {
		std::cout << "[" << req.method << "]: " << req.path << ": Response status: " << res.status << std::endl;
	});

	svr.Post("/signup", signup);
	svr.Post("/login", login);

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("0.0.0.0", 8080);
}
