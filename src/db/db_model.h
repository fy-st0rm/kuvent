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
			{ "NUMBER",   "TEXT",  .nullable = true },
			{ "TYPE",     "INT"  },
			{ "BATCH",    "TEXT", .nullable = true }
		}
	};

	static Table Events = {
		.name = "EVENTS",
		.format = {
			{ "ID",         "TEXT", .primary_key = true },
			{ "NAME",       "TEXT" },
			{ "START_DATE", "DATETIME" },
			{ "END_DATE",   "DATETIME" },
			{ "VENUE",      "TEXT" },
			{ "VENUE_DESC", "TEXT" },
			{ "DESC",       "TEXT" }
		}
	};

	static Table Flyers = {
		.name = "FLYERS",
		.format = {
			{ "ID",    "TEXT", .primary_key = true },
			{ "EVENT", "TEXT" }
		}
	};
}
