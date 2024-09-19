#ifndef ATTACK_BONUS_POTION_H
#define ATTACK_BONUS_POTION_H

#include "Item.h"

class AttackBonusPotion : public Item {
public:
    AttackBonusPotion();
private:
    Enchantment generateEnchantment();
};

#endif // ATTACK_BONUS_POTION_H
