#include "AttackBonusPotion.h"
#include <cstdlib> // for rand()

// Constructor definition
AttackBonusPotion::AttackBonusPotion() : Item(ItemType::ATTACK_BONUS_POTION) {
    setEnchantment(generateEnchantment());
}

// Method to generate enchantment for the attack bonus potion
Enchantment AttackBonusPotion::generateEnchantment() {
    return {EnhancementType::ATTACK_BONUS, rand() % 10 + 1}; 
}