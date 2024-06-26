#include <iostream>
#include <fstream>
#include "defines.h"
#include "file_transfer.h"
#include "uuid.h"

namespace route {

void upload(const Request& req, Response& res, const ContentReader &content_reader) {
	// The request needs to be a multipart form data
	if (!req.is_multipart_form_data()) {
		res.status = StatusCode::InternalServerError_500;
		res.set_content(
			"The request is not a multipart form data",
			"text/plain"
		);
		return;
	}

	// Collecting all the files
	MultipartFormDataItems files;
	content_reader(
		[&](const MultipartFormData &file) {
			files.push_back(file);
			return true;
		},
		[&](const char *data, size_t data_length) {
			files.back().content.append(data, data_length);
			return true;
		}
	);

	// Saving the files and generating unique ids
	std::vector<std::string> ids;
	for (MultipartFormData& file : files) {
		std::string id = uuid::generate_uuid_v4();
		std::ofstream f(DB_DIR + id + ".png");
		f << file.content;
		f.close();

		ids.push_back(id);
	}

	// Sending back the ids
	std::stringstream response;
	response << "{\"ids\": [";
	for (auto& id : ids) {
		response << "\"" + id + "\"";
		if (id != ids.back()) {
			response << ",";
		}
	}
	response << "]}";

	res.status = StatusCode::OK_200;
	res.set_content(response.str(), "application/json");
}

}
