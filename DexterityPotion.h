#ifndef DEXTERITY_POTION_H
#define DEXTERITY_POTION_H

#include "Item.h"

class DexterityPotion : public Item {
public:
    DexterityPotion();
private:
    Enchantment generateEnchantment();
};

#endif // DEXTERITY_POTION_H