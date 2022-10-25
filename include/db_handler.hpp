/*  Copyright 2022 Eric Lind

    Permission is hereby granted, free of charge,
    to any person obtaining a copy of this software and associated documentation files(the "Software"),
    to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute,
    sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions :

    The above copyright notice and this permission notice shall be included in all copies
    or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS",
    WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    ==============================================================================*/

#pragma once

#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "stats/character.hpp"
#include "stats/races.hpp"

namespace dndcg {
namespace db {

class DbHandler {
 public:
    explicit DbHandler(std::string db_file);
    ~DbHandler();

    void Open();
    void Close();

    std::vector<dndcg::races::Race> GetRaces();
    dndcg::races::Race GetRaceInfo(dndcg::races::RaceType race);
    std::unique_ptr<std::vector<std::pair<int, std::pair<std::string, std::string>>>> GetCharacters();

 private:
    std::unique_ptr<SQLite::Statement> get_characters_;
    std::shared_ptr<SQLite::Database> db_;
};
}  // namespace db
}  // namespace dndcg
