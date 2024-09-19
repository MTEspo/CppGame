#include "Boots.h"
#include <cstdlib> // for rand()

// Constructor definition
Boots::Boots() : Item(ItemType::BOOTS) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the boots
Enchantment Boots::generateEnchantment() {
    return {EnhancementType::DEXTERITY, rand() % 5 + 1};
}
