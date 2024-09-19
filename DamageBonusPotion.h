#ifndef DAMAGE_BONUS_POTION_H
#define DAMAGE_BONUS_POTION_H

#include "Item.h"

class DamageBonusPotion : public Item {
public:
    DamageBonusPotion();
private:
    Enchantment generateEnchantment();
};

#endif // DAMAGE_BONUS_POTION_H
