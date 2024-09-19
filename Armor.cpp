#include "Armor.h"
#include <cstdlib> // for rand()

// Constructor definition
Armor::Armor() : Item(ItemType::ARMOR) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the armor
Enchantment Armor::generateEnchantment() {
    return {EnhancementType::ARMOR_CLASS, rand() % 5 + 1};
}
