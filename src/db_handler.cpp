#include "db_handler.hpp"

#include "stats/races.hpp"

#include <iostream>
#include <string>

namespace {
static int callback(void* data, int argc, char** argv, char** azColName) {
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}
}  // namespace

namespace dndcg {
namespace db {

DbHandler::DbHandler(std::string db_file) {
    int retval = sqlite3_open(db_file.c_str(), &db);
    std::string query = "SELECT * FROM tblRaces;";

    sqlite3_exec(db, query.c_str(), callback, NULL, NULL);
}

std::vector<dndcg::races::Race>& DbHandler::GetRaces() {}

dndcg::races::Race& DbHandler::GetRaceInfo(dndcg::races::RaceType race) {}

DbHandler::~DbHandler() {
    Close();
}

void DbHandler::Close() {
    sqlite3_close(db);
}

}  // namespace db
}  // namespace dndcg
