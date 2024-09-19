#include "Belt.h"

Belt::Belt() : Item(ItemType::BELT) {
    setEnchantment(generateEnchantment());
}

Enchantment Belt::generateEnchantment() {
    EnhancementType types[] = {EnhancementType::CONSTITUTION, EnhancementType::STRENGTH};
    EnhancementType selectedType = types[rand() % 2];
    int bonus = rand() % 5 + 1;
    return {selectedType, bonus};
}