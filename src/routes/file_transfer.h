#pragma once

#include "httplib.h"
using namespace httplib;

namespace route {
	void upload(const Request& req, Response& res, const ContentReader &content_reader);
	void download(const Request& req, Response& res);
}
