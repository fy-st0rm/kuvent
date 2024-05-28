#pragma once

#include "db.h"

namespace model {
	static Table User = {
		.name = "User",
		.format = {
			{ "ID",       "TEXT", .primary_key = true },
			{ "USERNAME", "TEXT" },
			{ "EMAIL",    "TEXT" },
			{ "PASSWORD", "TEXT" },
			{ "TYPE",     "TEXT" }
		}
	};
}
