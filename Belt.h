#ifndef BELT_H
#define BELT_H

#include "Item.h" // Include the base class header
#include <cstdlib> // For rand()

/**
 * @file Belt.h
 * @brief Header file for the Belt class.
 * 
 * @details This file declares the Belt class, which represents a belt item in the game.
 * A belt can have specific enchantments that provide various enhancements to
 * characters' attributes or abilities.
 */

class Belt : public Item {
public:
    /**
     * @brief Constructor for the Belt class.
     * 
     * Initializes a belt item with a random enchantment.
     */
    Belt();

private:
    /**
     * @brief Generates a random enchantment for the belt.
     * 
     * This method overrides the generateEnchantment method in the base class (if applicable).
     * It specifically generates enchantments relevant to belts, such as enhancements
     * to ARMOR_CLASS or INTELLIGENCE.
     * 
     * @return An Enchantment struct with the selected type and bonus.
     */
    Enchantment generateEnchantment();
};

#endif