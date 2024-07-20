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

	svr.Get("/", [](const Request& req, Response& res) {
		res.set_content("Hello from kuvent backend ;3", "text/plain");
	});

	svr.Post("/signup", route::signup);
	svr.Post("/login", route::login);
	svr.Post("/upload", route::upload);
	svr.Get("/download/:id", route::download);

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("127.0.0.1", 8080);
}
