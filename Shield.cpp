#include "Shield.h"
#include <cstdlib> // for rand()

// Constructor definition
Shield::Shield() : Item(ItemType::SHIELD) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the shield
Enchantment Shield::generateEnchantment() {
    return {EnhancementType::ARMOR_CLASS, rand() % 5 + 1};
}
