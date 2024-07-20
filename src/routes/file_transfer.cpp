#include <iostream>
#include <fstream>
#include <filesystem>

#include "defines.h"
#include "file_transfer.h"
#include "uuid.h"
#include <vector>

namespace fs = std::filesystem;

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
		std::string name = file.filename;
		std::string ext = name.substr(name.find_last_of(".") + 1);
		std::string id = uuid::generate_uuid_v4();
		std::ofstream f(FLYER_DIR + id + "." + ext);
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

void download(const Request& req, Response& res) {
	std::string id = req.path_params.at("id");

	// Collecting all the flyers
	std::vector<std::string> flyers;
	for (const auto & entry : fs::directory_iterator(FLYER_DIR)) {
		flyers.push_back(entry.path().generic_string());
	}

	// Searching for flyer
	int i = 0;
	for (const auto& flyer : flyers) {
		if (flyer.find(id) != std::string::npos) {
			break;
		}
		i++;
	}

	// If the flyer doesnt exists
	if (i == flyers.size()) {
		std::stringstream response;
		response << "File with id: " << id << " doesn't exists.";
		res.status = StatusCode::NotFound_404;
		res.set_content(response.str(), "plain/text");
		return;
	}

	// Reading the file from disk and sending it to client
	std::string path = flyers[i];
	std::string ext = path.substr(path.find_last_of(".") + 1);
	std::ifstream file(path, std::ifstream::binary);
	std::stringstream buff;
	buff << file.rdbuf();

	res.status = StatusCode::OK_200;
	res.set_content(buff.str(), "image/" + ext);
}

}
