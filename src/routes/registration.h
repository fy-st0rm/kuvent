#pragma once

#include <iostream>

#include "httplib.h"
using namespace httplib;

void signup(const Request& req, Response& res);
void login(const Request& req, Response& res);
