#include "db.h"

Database::Database(const std::string& db) {
	int status = sqlite3_open(db.c_str(), &m_db);
	if (status) {
		std::cerr << "[DB ERROR]: " << sqlite3_errmsg(m_db) << std::endl;
		exit(1);
	}
}

Database::~Database() {
	sqlite3_close(m_db);
}

int Database::sqlite_callback(
	void* data,
	int argc,
	char** argv,
	char** attribute
) {
	SearchResult* result = (SearchResult*) data;
	
	SearchRow row;
	for (int i = 0; i < argc; i++) {
		const char* value = argv[i] ? argv[i] : "NULL";
		row.insert({
			std::string(attribute[i]), std::string(value)
		});
	}
	result->push_back(row);

	return 0;
}

QueryResult Database::query(const std::string& sql) {
	char* err;
	SearchResult result;
	int status = sqlite3_exec(
		m_db,
		sql.c_str(),
		sqlite_callback,
		(void*) &result,
		&err
	);

	return {
		.status = status,
		.error = err ? std::string(err) : "",
		.result = result
	};
}

QueryResult Database::create_table(Table table) {
	std::stringstream ss;

	ss << "CREATE TABLE " << table.name << "(";
	for (RowFormat& f : table.format) {
		ss << f.attribute << " " << f.data_type;

		if (f.primary_key)
			ss << " PRIMARY KEY";
		if (!f.nullable)
			ss << " NOT NULL";

		if (f != table.format.back())
			ss << ",";
	}
	ss << ");";

	return query(ss.str());
}

std::string Database::err_msg() {
	std::string err(sqlite3_errmsg(m_db));
	return err;
}
