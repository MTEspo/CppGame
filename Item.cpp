#include "Item.h"

Item::Item(ItemType itemType) : type(itemType) {}

void Item::setEnchantment(const Enchantment& newEnchantment) {
    enchantment = newEnchantment;
}

ItemType Item::getType() const {
    return type;
}

Enchantment Item::getEnchantment() const {
    return enchantment;
}

std::string Item::enchantmentTitle(EnhancementType type) {
    switch (type) {
        case EnhancementType::STRENGTH: return "STRENGTH";
        case EnhancementType::DEXTERITY: return "DEXTERITY";
        case EnhancementType::CONSTITUTION: return "CONSTITUTION";
        case EnhancementType::INTELLIGENCE: return "INTELLIGENCE";
        case EnhancementType::WISDOM: return "WISDOM";
        case EnhancementType::CHARISMA: return "CHARISMA";
        case EnhancementType::ARMOR_CLASS: return "ARMOR_CLASS";
        case EnhancementType::ATTACK_BONUS: return "ATTACK_BONUS";
        case EnhancementType::DAMAGE_BONUS: return "DAMAGE_BONUS";
        default: return "UNKNOWN";
    }
}
std::string Item::itemTypeToString(ItemType type) {
    switch (type) {
        case ItemType::HELMET: return "HELMET";
        case ItemType::RING: return "RING";
        case ItemType::WEAPON: return "WEAPON";
        case ItemType::SHIELD: return "SHIELD";
        case ItemType::ARMOR: return "ARMOR";
        case ItemType::BOOTS: return "BOOTS";
        case ItemType::BELT: return "BELT";
        case ItemType::HEALTH_POTION: return "HEALTH_POTION";
        case ItemType::STRENGTH_POTION: return "STRENGTH_POTION";
        case ItemType::DEXTERITY_POTION: return "DEXTERITY_POTION";
        case ItemType::CONSTITUTION_POTION: return "CONSTITUTION_POTION";
        case ItemType::INTELLIGENCE_POTION: return "INTELLIGENCE_POTION";
        case ItemType::WISDOM_POTION: return "WISDOM_POTION";
        case ItemType::CHARISMA_POTION: return "CHARISMA_POTION";
        case ItemType::ARMOR_CLASS_POTION: return "ARMOR_CLASS_POTION";
        case ItemType::ATTACK_BONUS_POTION: return "ATTACK_BONUS_POTION";
        case ItemType::DAMAGE_BONUS_POTION: return "DAMAGE_BONUS_POTION";
        default: return "UNKNOWN";
    }
}

