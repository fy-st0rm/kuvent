#include "httplib.h"
using namespace httplib;

#include "db/db.h"
#include "routes/routes.h"

#include "jsoncpp.cpp"
#include "db/db.cpp"
#include "routes/file_transfer.cpp"
#include "routes/participation.cpp"
#include "routes/post.cpp"
#include "routes/registration.cpp"


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
	svr.Post("/update_profile", route::update_profile);
	svr.Get("/get_profile/:user_id", route::get_profile);

	svr.Post("/upload", route::upload);
	svr.Get("/download/:id", route::download);

	svr.Post("/post_event", route::post_event);
	svr.Post("/delete_event", route::delete_event);
	svr.Get("/get_event", route::get_event);
	svr.Get("/get_flyer/:event_id", route::get_flyer);
	svr.Get("/get_participants/:event_id", route::get_participants);

	svr.Post("/join_event", route::join_event);
	svr.Post("/leave_event", route::leave_event);
	svr.Post("/is_registered", route::is_registered);

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("127.0.0.1", 8080);
}
