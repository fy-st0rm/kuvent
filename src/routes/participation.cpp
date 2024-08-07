#include <sstream>

#include "routes.h"
#include "json/json.h"
#include "db/db.h"
#include "defines.h"

namespace route {

void join_event(const Request& req, Response& res) {
	Json::Value payload;
	Json::Reader reader;
	reader.parse(req.body, payload);

	std::string event_id = payload["event_id"].asString();
	std::string user_id = payload["user_id"].asString();

	Database db(DB_PATH);

	std::stringstream sq;
	sq
		<< "SELECT * FROM EVENTS "
		<< "WHERE ID = \"" << event_id << "\";";

	QueryResult r = db.query(sq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	if (r.result.size() == 0) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Cannot find event with id: " + event_id, "text/plain");
		return;
	}

	std::stringstream iq;
	iq
		<< "INSERT INTO PARTICIPANTS "
		<< "VALUES ("
		<< "\"" << event_id << "\","
		<< "\"" << user_id << "\""
		<< ");";

	r = db.query(iq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	res.status = StatusCode::OK_200;
	res.set_content("Sucessfully joined the event", "text/plain");
}

void leave_event(const Request& req, Response& res) {
	Json::Value payload;
	Json::Reader reader;
	reader.parse(req.body, payload);

	std::string event_id = payload["event_id"].asString();
	std::string user_id = payload["user_id"].asString();

	Database db(DB_PATH);

	std::stringstream sq;
	sq
		<< "SELECT * FROM PARTICIPANTS "
		<< "WHERE USER_ID = \"" << user_id << "\" AND "
		<< "EVENT_ID = \"" << event_id << "\";";

	QueryResult r = db.query(sq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	if (r.result.size() == 0) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Invalid participant or event id", "text/plain");
		return;
	}

	std::stringstream dq;
	dq
		<< "DELETE FROM PARTICIPANTS "
		<< "WHERE USER_ID = \"" << user_id << "\" AND "
		<< "EVENT_ID = \"" << event_id << "\";";

	r = db.query(dq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	res.status = StatusCode::OK_200;
	res.set_content("Sucessfully left the event", "text/plain");
}

void is_registered(const Request& req, Response& res) {
	Json::Value payload;
	Json::Reader reader;
	reader.parse(req.body, payload);

	std::string user_id = payload["user_id"].asString();
	std::string event_id = payload["event_id"].asString();

	Database db(DB_PATH);

	std::stringstream sq;
	sq
		<< "SELECT * FROM PARTICIPANTS "
		<< "WHERE USER_ID = \"" << user_id << "\" AND "
		<< "EVENT_ID = \"" << event_id << "\";";

	QueryResult r = db.query(sq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	Json::Value response;
	Json::StyledWriter writer;

	if (
		r.result.size() == 0 ||
		r.result.front()["EVENT_ID"] != event_id
	) {
		response["registered"] = false;
	} else {
		response["registered"] = true;
	}

	res.status = StatusCode::OK_200;
	res.set_content(writer.write(response), "application/json");
}

}
