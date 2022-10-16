#include "character.hpp"

namespace dndcg {
namespace characters {
Character::Character() : name(), age() {}
Character::Character(std::string value) : name(value), age() {}
}  // namespace characters
}  // namespace dndcg