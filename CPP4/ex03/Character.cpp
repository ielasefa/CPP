#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string& name) : name(name) { for (int i = 0; i < 4; ++i) inventory[i] = 0; }
Character::Character(const Character &other) : name(other.name) { for (int i = 0; i < 4; ++i) inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : 0; }
Character & Character::operator=(const Character &other) { if (this != &other) { name = other.name; for (int i = 0; i < 4; ++i) { if (inventory[i]) { delete inventory[i]; inventory[i] = 0; } if (other.inventory[i]) inventory[i] = other.inventory[i]->clone(); } } return *this; }
Character::~Character() { for (int i = 0; i < 4; ++i) if (inventory[i]) { delete inventory[i]; inventory[i] = 0; } }
std::string const & Character::getName() const { return name; }
void Character::equip(AMateria* m) { if (!m) return; for (int i = 0; i < 4; ++i) { if (!inventory[i]) { inventory[i] = m; return; } } }
void Character::unequip(int idx) { if (idx < 0 || idx >= 4) return; inventory[idx] = 0; }
void Character::use(int idx, ICharacter& target) { if (idx < 0 || idx >= 4) return; if (inventory[idx]) inventory[idx]->use(target); }
