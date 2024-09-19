#ifndef BOOTS_H
#define BOOTS_H

#include "Item.h"

/**
 * @file Boots.h
 * @brief Header file for the Boots class.
 * 
 * @details This file contains the declaration of the Boots class, which represents 
 * a pair of boots item in a d20-based game.
 */

/**
 * @class Boots
 * @brief Represents a pair of boots item in the game.
 * 
 * @details The Boots class inherits from the Item class and provides functionality 
 * specific to boots items, such as generating enchantments related to dexterity.
 */
class Boots : public Item {
public:
    /**
     * @brief Constructs a Boots object.
     * 
     * @details Initializes the Boots object with a random enchantment related to 
     * dexterity.
     */
    Boots();
    
private:
    /**
     * @brief Generates a random enchantment for the boots.
     * 
     * @return The randomly generated enchantment.
     * 
     * @details This method randomly selects an enhancement type (such as DEXTERITY) 
     * and generates a random bonus value between 1 and 5.
     */
    Enchantment generateEnchantment();
};

#endif // BOOTS_H

