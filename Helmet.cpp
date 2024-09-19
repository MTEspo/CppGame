#include "Helmet.h"
 // for rand()

// Constructor definition
Helmet::Helmet() : Item(ItemType::HELMET) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the helmet
Enchantment Helmet::generateEnchantment() {
    // Array of possible enchants
    EnhancementType types[] = {EnhancementType::ARMOR_CLASS, EnhancementType::WISDOM, EnhancementType::INTELLIGENCE};

    // Randomly choose an enchantment type
    EnhancementType selectedType = types[rand() % 2];

    // Generate a random bonus for the enchantment
    int bonus = rand() % 5 + 1;

    // Return the generated enchantment
    return {selectedType, bonus};
}
