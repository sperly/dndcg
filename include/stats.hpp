#pragma once

#include <vector>

namespace dndcg {
namespace stats {

struct DiceStats {
    int numberOfRolls;
    int dieSize;
    int modifier;
    int normal;
};

struct Movements {
    int land;
    int water;
    int air;
};

struct PlayerStats {
    int strength;
    int size;
    int physique;
    int agility;
    int intelligence;
    int psyche;
    int charisma;
};

struct Stats {
    DiceStats strength;
    DiceStats size;
    DiceStats physique;
    DiceStats agility;
    DiceStats intelligence;
    DiceStats psyche;
    DiceStats charisma;
};

}  // namespace stats
}  // namespace dndcg