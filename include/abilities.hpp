#pragma once

#include <string>

namespace dndcg {
namespace abilities {
class Ability {
   public:
    std::string name;
    int abilityValue;
};

class CharacterAbility : public Ability {
   public:
    int experience;
};
}  // namespace abilities
}  // namespace dndcg