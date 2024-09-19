#ifndef RING_H
#define RING_H

#include "Item.h"

/**
 * @file Ring.h
 * @brief Header file for the Ring class.
 * 
 * @details This file declares the Ring class, which represents a ring item in the game.
 */

/**
 * @class Ring
 * @brief Represents a ring item.
 * 
 * @details The Ring class inherits from the Item class and represents a ring item in the game.
 */
class Ring : public Item {
public:
    /**
     * @brief Constructor for the Ring class.
     * 
     * @details This constructor initializes a Ring object with its ItemType set to RING and generates an enchantment for the ring.
     */
    Ring();
private:
    /**
     * @brief Generates an enchantment for the ring.
     * 
     * @details This method randomly generates an enchantment for the ring based on the EnhancementType enum class.
     * 
     * @return The generated enchantment for the ring.
     */
    Enchantment generateEnchantment();
};

#endif // RING_H

