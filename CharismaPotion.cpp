#include "CharismaPotion.h"
#include <cstdlib> // for rand()

// Constructor definition
CharismaPotion::CharismaPotion() : Item(ItemType::CHARISMA_POTION) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the charisma potion
Enchantment CharismaPotion::generateEnchantment() {
    return {EnhancementType::CHARISMA, rand() % 10 + 1}; 
}
