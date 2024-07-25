#include "routes.h"
#include "uuid.h"
#include "defines.h"
#include "db/db.h"
#include "json/json.h"

namespace route {

void post_event(const Request& req, Response& res) {
	Json::Value value;
	Json::Reader reader;
	reader.parse(req.body, value);

	std::string id = uuid::generate_uuid_v4();
	std::string event_name = value["name"].asString();
	std::string start_date = value["start_date"].asString();
	std::string end_date = value["end_date"].asString();
	std::string venue = value["venue"].asString();
	std::string venue_desc = value["venue_desc"].asString();
	std::string desc = value["desc"].asString();
	Json::Value flyers = value["flyers"];

	Database db(DB_PATH);

	// Inserting the event
	std::stringstream iq;
	iq
		<< "INSERT INTO EVENTS "
		<< "VALUES ("
		<< "\"" << id << "\","
		<< "\"" << event_name << "\","
		<< "\"" << start_date << "\","
		<< "\"" << end_date << "\","
		<< "\"" << venue << "\","
		<< "\"" << venue_desc << "\","
		<< "\"" << desc << "\""
		<< ");";

	QueryResult r = db.query(iq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	// Inserting flyer
	for (auto flyer : flyers) {
		std::stringstream fiq;
		fiq
			<< "INSERT INTO FLYERS "
			<< "VALUES ("
			<< "\"" << flyer.asString() << "\","
			<< "\"" << id << "\""
			<< ");";

		QueryResult r = db.query(fiq.str());
		if (r.status != SQLITE_OK) {
			res.status = StatusCode::InternalServerError_500;
			res.set_content(db.err_msg(), "text/plain");
			return;
		}
	}

	res.status = StatusCode::OK_200;
	res.set_content("{ \"event_id\": " + id + " }", "application/json");
}

void get_event(const Request& req, Response& res) {
	Database db(DB_PATH);

	// Getting all the event
	std::stringstream sq;
	sq << "SELECT * FROM EVENTS;";

	QueryResult r = db.query(sq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	// Collecting event data
	Json::Value response;
	for (auto row : r.result) {
		Json::Value event;
		for (auto [key, value] : row) {
			event[key] = value;
		}
		response[row["ID"]] = event;
	}

	Json::StyledWriter writer;
	std::string response_str = writer.write(response);

	res.status = StatusCode::OK_200;
	res.set_content(response_str, "application/json");
}

void get_flyer(const Request& req, Response& res) {
	std::string id = req.path_params.at("event_id");

	Database db(DB_PATH);

	// Searching for flyer from that event
	std::stringstream sq;
	sq
		<< "SELECT * FROM FLYERS "
		<< "WHERE EVENT = \"" << id << "\";";

	QueryResult r = db.query(sq.str());
	if (r.status != SQLITE_OK) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(db.err_msg(), "text/plain");
		return;
	}

	// When the flyer doesnt exists
	if (r.result.size() == 0) {
		res.status = StatusCode::BadRequest_400;
		res.set_content("Cannot find flyers for event with id: " + id, "text/plain");
		return;
	}

	// Collecting data
	Json::Value response;
	Json::Value flyers;
	for (auto row : r.result) {
		flyers.append(row["ID"]);
	}
	response["flyers"] = flyers;

	Json::StyledWriter writer;
	std::string response_str = writer.write(response);

	res.status = StatusCode::OK_200;
	res.set_content(response_str, "application/json");
}

}
