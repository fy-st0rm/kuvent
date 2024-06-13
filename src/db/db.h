#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "sqlite3.h"

struct RowFormat {
	std::string attribute;
	std::string data_type;
	bool primary_key = false;
	bool nullable = false;

	bool operator ==(const RowFormat& f) {
		return (attribute == f.attribute) &&
			(data_type == f.data_type) &&
			(primary_key == f.primary_key) &&
			(nullable == f.nullable);
	}

	bool operator !=(const RowFormat& f) {
		return (attribute != f.attribute) ||
			(data_type != f.data_type) ||
			(primary_key != f.primary_key) ||
			(nullable != f.nullable);
	}
};

struct Table {
	std::string name;
	std::vector<RowFormat> format;
};

typedef std::unordered_map<std::string, std::string> SearchRow;
typedef std::vector<SearchRow> SearchResult;

struct QueryResult {
	int status;
	std::string error;
	SearchResult result;
};

class Database {
public:
	Database(const std::string& db);
	~Database();

	QueryResult query(const std::string& sql);
	QueryResult create_table(Table table);
	std::string err_msg();

private:
	static int sqlite_callback(
		void* data,
		int argc,
		char** argv,
		char** attribute
	);

private:
	sqlite3 *m_db;
};
