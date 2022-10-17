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