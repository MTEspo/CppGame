#include "DexterityPotion.h"
#include <cstdlib> // for rand()


DexterityPotion::DexterityPotion() : Item(ItemType::DEXTERITY_POTION) {
    setEnchantment(generateEnchantment());
}


Enchantment DexterityPotion::generateEnchantment() {
    return {EnhancementType::DEXTERITY, rand() % 10 + 1}; 
}
