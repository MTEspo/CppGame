#ifndef ARMOR_CLASS_POTION_H
#define ARMOR_CLASS_POTION_H

#include "Item.h"

class ArmorClassPotion : public Item {
public:
    ArmorClassPotion();
private:
    Enchantment generateEnchantment();
};

#endif // ARMOR_CLASS_POTION_H