#pragma once

#include <sqlite3.h>

#include <string>

namespace dndcg {
namespace db {

class DbHandler {
   public:
    DbHandler(std::string db_file);
    ~DbHandler();

    void Open();
    void Close();

    std::vector<dndcg::races::Race>& DbHandler::GetRaces();
    dndcg::races::Race& DbHandler::GetRaceInfo(dndcg::races::RaceType race);

   private:
    sqlite3* db;
};
}  // namespace db
}  // namespace dndcg