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

#include <string>
#include <vector>

#include "stats/stats.hpp"

namespace dndcg {
namespace races {
enum class RaceType {
    HUMAN = 0,
    DUCK,
    HALFLING,
    KARKION,
    CATMAN,
    CENTAUR,
    MINOTAUR,
    ONAQUI,
    REPTILEMAN,
    CYCLOPS,
    DWARF,
    SUPERGIGANT,
    STONEBITER,
    TITAN,
    TROGLODYTE,
    ILLGOBLIN,
    CAVETROLL,
    GIANT,
    ORCH,
    HALFORCH,
    LINDSKIR,
    GIANTLING,
    BLACKELF,
    BLACKELFLING,
    FORESTTROLL,
    WOLFMAN,
    BLOODELF,
    SEAELF,
    HIGHELF,
    LIGHTELF,
    CAVEELF,
    SILVERELF,
    FORRESTELF,
    GRAYELF,
    NYMPH,
    SATYRE,
    FORRESTNYMPH,
    SWANNMAIDEN,
    FARIE,
    WAREWOLF,
    SHARKMAN,
    RATMAN,
    SERPENT,
    PUSSRAT,
    GOBLIN,
    FROSTELF,
    SEAFARIE,
    FENFIRE,
    GNOME,
    DRYAD,
    HAG,
    NAJAD,
    OREAD,
    LEPRICHAUN,
    DEERLING,
    SEALLING,
    EAGLEMAN,
    SIREN,
    MERMAID,
    YETI,
    HALFELF,
    HIGHMAN,
    MAGIR,
    RAGMAN,
    FORRESTMAN,
};

class Race {
 public:
    std::string name;
    stats::Stats stats;
    int bodyPoints;
    stats::Movements movements;
};

class RaceInfo {
 public:
    std::vector<races::Race> Races{};
};
}  // namespace races
}  // namespace dndcg
