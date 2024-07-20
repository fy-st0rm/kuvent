#include "db.h"
#include "db_model.h"
#include "defines.h"

int main() {
	Database db(DB_PATH);

	QueryResult r = db.create_table(model::User);
	if (r.status != SQLITE_OK) {
		std::cerr << r.error << std::endl;
		return 1;
	}

	r = db.create_table(model::Events);
	if (r.status != SQLITE_OK) {
		std::cerr << r.error << std::endl;
		return 1;
	}

	r = db.create_table(model::Flyers);
	if (r.status != SQLITE_OK) {
		std::cerr << r.error << std::endl;
		return 1;
	}

	return 0;
}
