#pragma once

#include "db.h"

namespace model {
	static Table User = {
		.name = "USER",
		.format = {
			{ "ID",       "TEXT", .primary_key = true },
			{ "USERNAME", "TEXT" },
			{ "EMAIL",    "TEXT" },
			{ "PASSWORD", "TEXT" },
			{ "TYPE",     "INT"  }
		}
	};
}
