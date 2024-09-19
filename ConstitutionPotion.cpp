#include "ConstitutionPotion.h"
#include <cstdlib> // for rand()

// Constructor definition
ConstitutionPotion::ConstitutionPotion() : Item(ItemType::CONSTITUTION_POTION) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the constitution potion
Enchantment ConstitutionPotion::generateEnchantment() {
    return {EnhancementType::CONSTITUTION, rand() % 10 + 1}; 
}
