#pragma once

#include <string>
#include <vector>

#include "abilities.hpp"
#include "races.hpp"
#include "stats.hpp"
#include "weapons.hpp"

namespace dndcg {
namespace characters {

enum class Gender { MALE = 0, FEMALE, NONBINARY, HERMAFRODITE, NO_GENDER };

enum class SocialStatus {
    NOBLE = 0,
    HIGH_CLASS,
    MIDDLE_CLASS,
    LOW_CLASS,
    CLASS_LESS
};

class Character {
   public:
    Character();
    Character(std::string name);

   private:
    std::string playerName;
    std::string gameLeaderName;
    std::string name;
    enum races::RaceType race;
    enum Gender gender;
    unsigned int age;
    std::string occupation;
    enum SocialStatus socialStatus;
    std::string birthPlace;

    stats::Stats basicStats;
    int bodyPoints;
    stats::Movements movement;
    int bonusExperiensPoints;
    std::vector<abilities::CharacterAbility> abilitiea;
    std::vector<std::string> heroAbilities;
    int heroPoints;
    std::vector<weapons::Weapon> weapons;
};
}  // namespace characters
}  // namespace dndcg
