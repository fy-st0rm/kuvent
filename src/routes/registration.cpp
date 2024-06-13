#include <sstream>

#include "db/db.h"
#include "registration.h"
#include "json/json.h"
#include "uuid.h"
#include "defines.h"

void signup(const Request& req, Response& res) {
	Json::Value value;
	Json::Reader reader;
	reader.parse(req.body, value);

	std::string id = uuid::generate_uuid_v4();
	std::string username = value["username"].asString();
	std::string email = value["email"].asString();
	std::string password = value["password"].asString();
	std::string type = value["type"].asString();

	Database db(DB_PATH);

	std::stringstream sq;
	sq << "SELECT * FROM USER WHERE EMAIL = \"" << email << "\";";

	QueryResult r = db.query(sq.str());

	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	// Checking for already registered email
	if (r.result.size() != 0) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Your email has already been registered.", "text/plain");
		return;
	}

	// Inserting new user data
	std::stringstream iq;
	iq << "INSERT INTO USER VALUES (\"" << id << "\",\"" << username << "\",\"" << email << "\",\"" << password << "\",\"" << type << "\");";

	r = db.query(iq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	res.status = StatusCode::OK_200;
	res.set_content("Email has sucessfully been registered.", "text/plain");
}

void login(const Request& req, Response& res) {
	Json::Value value;
	Json::Reader reader;
	reader.parse(req.body, value);

	std::string email = value["email"].asString();
	std::string password = value["password"].asString();

	Database db(DB_PATH);

	std::stringstream sq;
	sq << "SELECT * FROM USER WHERE EMAIL = \"" << email << "\";";

	QueryResult r = db.query(sq.str());

	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	// Checking if email has been registered
	if (r.result.size() == 0) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Your email hasn\'t been registered.", "text/plain");
		return;
	}

	SearchRow row = r.result.front();

	// Checking the password
	if (password != row["PASSWORD"]) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Incorrect password.", "text/plain");
		return;
	}

	std::string id = row["ID"];
	std::string username = row["USERNAME"];

	std::stringstream response;
	response << "{"
		<< "\"id\": \"" << id << "\","
		<< "\"username\": \"" << username << "\""
	<< "}";

	res.status = StatusCode::OK_200;
	res.set_content(response.str(), "application/json");
}
