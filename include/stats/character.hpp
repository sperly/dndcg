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

#include "stats/abilities.hpp"
#include "stats/races.hpp"
#include "stats/stats.hpp"
#include "stats/weapons.hpp"

namespace dndcg {
namespace characters {

enum class Gender { MALE = 0, FEMALE, NONBINARY, HERMAFRODITE, NO_GENDER };

enum class SocialStatus { NOBLE = 0, HIGH_CLASS, MIDDLE_CLASS, LOW_CLASS, CLASS_LESS };

class Character {
 public:
    explicit Character(std::string name);
    Character();

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
