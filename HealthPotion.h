#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "Item.h"


class HealthPotion : public Item {
public:
    HealthPotion();
private:
    Enchantment generateEnchantment();  
};



#endif 