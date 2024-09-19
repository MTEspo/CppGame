#include "ArmorClassPotion.h"
#include <cstdlib> // for rand()

// Constructor definition
ArmorClassPotion::ArmorClassPotion() : Item(ItemType::ARMOR_CLASS_POTION) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the armor class potion
Enchantment ArmorClassPotion::generateEnchantment() {
    return {EnhancementType::ARMOR_CLASS, rand() % 10 + 1}; 
}
