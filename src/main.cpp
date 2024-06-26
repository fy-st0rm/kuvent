#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
using namespace httplib;

#include "db/db.h"
#include "routes/registration.h"
#include "routes/file_transfer.h"

int main(void) {
	Server svr;

	svr.set_logger([](const Request& req, const Response& res) {
		std::cout << "[" << req.method << "]: " << req.path << ": Response status: " << res.status << std::endl;
	});

	svr.Post("/signup", route::signup);
	svr.Post("/login", route::login);
	svr.Post("/upload", route::upload);

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("0.0.0.0", 8080);
}
