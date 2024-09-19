#include "HealthPotion.h"
#include <cstdlib> 


HealthPotion::HealthPotion() : Item(ItemType::HEALTH_POTION) {
    setEnchantment(generateEnchantment());
}


Enchantment HealthPotion::generateEnchantment() {
    return {EnhancementType::HEALTH, rand() % 10 + 1}; 
}