#pragma once

#include <string>

namespace dndcg {
namespace weapons {

enum class Grip { ONE_HAND = 0, TWO_HAND, SECOND_HAND, FOOT };

class Weapon {
   public:
    std::string name;
    enum Grip grip;
    int skillLevel;
    int damage;
    int BV;
    int length;
    int reach;
    int experience;
    int wheight;
};
}  // namespace weapons
}  // namespace dndcg