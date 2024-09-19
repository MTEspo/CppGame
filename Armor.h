#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

/**
 * @file Armor.h
 * @brief Header file for the Armor class.
 * 
 * @details This file contains the declaration of the Armor class, which represents 
 * an armor item in a d20-based game.
 */

/**
 * @class Armor
 * @brief Represents an armor item in the game.
 * 
 * @details The Armor class inherits from the Item class and provides functionality 
 * specific to armor items, such as generating enchantments related to armor class.
 */
class Armor : public Item {
public:
    /**
     * @brief Constructs an Armor object.
     * 
     * @details Initializes the Armor object with a random enchantment related to 
     * armor class.
     */
    Armor();
    
private:
    /**
     * @brief Generates a random enchantment for the armor.
     * 
     * @return The randomly generated enchantment.
     * 
     * @details This method randomly selects an enhancement type (such as ARMOR_CLASS) 
     * and generates a random bonus value between 1 and 5.
     */
    Enchantment generateEnchantment();
};

#endif // ARMOR_H

