#ifndef INTELLIGENCE_POTION_H
#define INTELLIGENCE_POTION_H

#include "Item.h"

class IntelligencePotion : public Item {
public:
    IntelligencePotion();
private:
    Enchantment generateEnchantment();
};

#endif // INTELLIGENCE_POTION_H
