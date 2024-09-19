#ifndef CONSTITUTION_POTION_H
#define CONSTITUTION_POTION_H

#include "Item.h"

class ConstitutionPotion : public Item {
public:
    ConstitutionPotion();
private:
    Enchantment generateEnchantment();
};

#endif // CONSTITUTION_POTION_H
