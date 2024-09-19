#include "IntelligencePotion.h"
#include <cstdlib> // for rand()

// Constructor definition
IntelligencePotion::IntelligencePotion() : Item(ItemType::INTELLIGENCE_POTION) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the intelligence potion
Enchantment IntelligencePotion::generateEnchantment() {
    return {EnhancementType::INTELLIGENCE, rand() % 10 + 1}; 
}
