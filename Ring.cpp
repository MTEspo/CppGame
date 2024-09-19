#include "Ring.h"
#include <cstdlib> // for rand()

// Constructor definition
Ring::Ring() : Item(ItemType::RING) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the ring
Enchantment Ring::generateEnchantment() {
    EnhancementType types[] = {EnhancementType::STRENGTH, EnhancementType::DEXTERITY, EnhancementType::CONSTITUTION,
                                EnhancementType::INTELLIGENCE, EnhancementType::WISDOM, EnhancementType::CHARISMA};
    return {types[rand() % 6], rand() % 5 + 1};
}
