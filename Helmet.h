#ifndef HELMET_H
#define HELMET_H

#include "Item.h"

/**
 * @file Helmet.h
 * @brief Header file for the Helmet class.
 * 
 * @details This file declares the Helmet class, which represents a type of item
 * worn on the head by characters in the game. Helmets can provide various enchantments
 * to enhance the character's abilities or attributes.
 */

/**
 * @class Helmet
 * @brief Represents a helmet item in the game.
 * 
 * @details The Helmet class inherits from the Item class and represents a type of 
 * item worn on the head by characters in the game. Helmets can have different types 
 * of enchantments that enhance the character's attributes or abilities.
 */
class Helmet : public Item {
public:
    /**
     * @brief Constructor for the Helmet class.
     * 
     * @details This constructor initializes a Helmet object and generates a random 
     * enchantment for the helmet using the generateEnchantment method.
     */
    Helmet();

private:
    /**
     * @brief Method to generate a random enchantment for the helmet.
     * 
     * @details This method generates a random enchantment for the helmet, 
     * which can include enhancements to attributes such as armor class or intelligence.
     * 
     * @return The generated enchantment for the helmet.
     */
    Enchantment generateEnchantment();
};

#endif // HELMET_H
