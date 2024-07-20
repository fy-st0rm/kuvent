#include <sstream>

#include "db/db.h"
#include "routes.h"
#include "json/json.h"
#include "uuid.h"
#include "defines.h"
#include "account_type.h"

namespace route {

void signup(const Request& req, Response& res) {
	Json::Value value;
	Json::Reader reader;
	reader.parse(req.body, value);

	std::string id = uuid::generate_uuid_v4();
	std::string username = value["username"].asString();
	std::string email = value["email"].asString();
	std::string password = value["password"].asString();
	AccountType type = (AccountType) value["type"].asInt();

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
	iq << "INSERT INTO USER (ID, USERNAME, EMAIL, PASSWORD, TYPE) VALUES (\"" << id << "\",\"" << username << "\",\"" << email << "\",\"" << password << "\",\"" << type << "\");";

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

	// Creating response
	std::string id = row["ID"];
	std::string username = row["USERNAME"];
	std::string r_email = row["EMAIL"];
	int number = NULL;
	if (row["NUMBER"] != "NULL") {
		number = std::stoi(row["NUMBER"]);
	}
	int acc_type = std::stoi(row["TYPE"]);
	std::string batch = row["BATCH"];

	Json::Value response;
	response["id"] = id;
	response["username"] = username;
	response["email"] = r_email;
	response["number"] = number;
	response["account_type"] = acc_type;
	response["batch"] = batch;

	Json::StyledWriter writer;
	std::string response_str = writer.write(response);

	res.status = StatusCode::OK_200;
	res.set_content(response_str, "application/json");
}

}
