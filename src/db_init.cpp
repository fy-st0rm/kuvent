#include "db.h"
#include "db_model.h"

int main() {
	Database db("db/database.db");
	QueryResult r = db.create_table(model::User);
	if (r.status != SQLITE_OK) {
		std::cerr << r.error << std::endl;
		return 1;
	}
	return 0;
}
