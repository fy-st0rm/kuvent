#pragma once

#include "httplib.h"
using namespace httplib;

namespace route {
	void signup(const Request& req, Response& res);
	void login(const Request& req, Response& res);
}
