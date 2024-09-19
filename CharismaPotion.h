#ifndef CHARISMA_POTION_H
#define CHARISMA_POTION_H

#include "Item.h"

class CharismaPotion : public Item {
public:
    CharismaPotion();
private:
    Enchantment generateEnchantment();
};

#endif // CHARISMA_POTION_H
