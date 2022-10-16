#pragma once

#include <string>

#include "stats.hpp"

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

struct Race {
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