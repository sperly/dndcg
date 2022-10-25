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
    db_ = std::make_shared<SQLite::Database>(db_file.c_str(), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE | SQLite::OPEN_FULLMUTEX);
    // int retval = sqlite3_open(db_file.c_str(), db_);
    SQLite::Transaction transaction(*db_);
    // std::string query = "SELECT * FROM tblRaces;";
    // sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

    get_characters_ = std::make_unique<SQLite::Statement>(
        *db_, "SELECT c.idx, c.name, r.name FROM tblCharacter c INNER JOIN tblRaces r ON c.race = r.type;");
}

std::vector<dndcg::races::Race> DbHandler::GetRaces() {
    return std::vector<dndcg::races::Race>();
}

dndcg::races::Race DbHandler::GetRaceInfo(dndcg::races::RaceType race) {}

std::unique_ptr<std::vector<std::pair<int, std::pair<std::string, std::string>>>> DbHandler::GetCharacters() {
    // "SELECT c.idx, c.name, r.name FROM tblCharacter c INNER JOIN tblRaces r ON c.race = r.type WHERE c.idx=0;";
    // std::string query = "SELECT * FROM tblRaces;";
    // add_query_->bind(8, static_cast<int64_t>(job.updated_time));
    std::vector<std::pair<int, std::pair<std::string, std::string>>> chars;
    while (get_characters_->executeStep()) {
        chars.emplace_back(
            std::make_pair(get_characters_->getColumn(0).getUInt(),
                           std::make_pair(get_characters_->getColumn(1).getString(), get_characters_->getColumn(2).getString())));
    }
    get_characters_->reset();

    return std::make_unique<std::vector<std::pair<int, std::pair<std::string, std::string>>>>(chars);
}

DbHandler::~DbHandler() {
    Close();
}

void DbHandler::Close() {}

}  // namespace db
}  // namespace dndcg
