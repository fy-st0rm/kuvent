#pragma once

#include "httplib.h"
using namespace httplib;

namespace route {

	// Registration
	void signup(const Request& req, Response& res);
	void login(const Request& req, Response& res);
	void update_profile(const Request& req, Response& res);

	// File transfer
	void upload(const Request& req, Response& res, const ContentReader &content_reader);
	void download(const Request& req, Response& res);

	// Post
	void post_event(const Request& req, Response& res);
	void get_event(const Request& req, Response& res);
	void get_flyer(const Request& req, Response& res);

	// Participation
	void join_event(const Request& req, Response& res);
	void leave_event(const Request& req, Response& res);

}
