#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
#include "db.h"

using namespace httplib;

int main(void) {
	Database db("db/database.db");

	QueryResult rs;
	rs = db.query(
		"SELECT * FROM User WHERE ID=1;"
	);
	if (rs.status != SQLITE_OK) {
		std::cerr << rs.error << std::endl;
		return 1;
	}

	for (auto r : rs.result) {
		for (auto a : r) {
			std::cout << a.first << ": " << a.second << "\t";
		}
		std::cout << std::endl;
	}

	Server svr;
	svr.Get("/", [](const Request& req, Response& res) {
		res.set_content("Hello World!", "text/plain");
	});

	std::cout << "Server listening on: http://localhost:8080" << std::endl;
	svr.listen("0.0.0.0", 8080);
}
