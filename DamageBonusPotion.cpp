#include "DamageBonusPotion.h"
#include <cstdlib> 

DamageBonusPotion::DamageBonusPotion() : Item(ItemType::DAMAGE_BONUS_POTION) {
    setEnchantment(generateEnchantment());
}

Enchantment DamageBonusPotion::generateEnchantment() {
    return {EnhancementType::DAMAGE_BONUS, rand() % 10 + 1}; 
}