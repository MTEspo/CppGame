#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "EnhancementType.h"

/**
 * @file Enchantment.h
 * @brief Header file for the Enchantment struct.
 * 
 * @details This file contains the declaration of the Enchantment struct, which represents 
 * an enchantment applied to an item in a d20-based game.
 */

/**
 * @struct Enchantment
 * @brief Represents an enchantment applied to an item.
 * 
 * @details The Enchantment struct contains two members: type and bonus. The type 
 * represents the type of enhancement (such as STRENGTH or ARMOR_CLASS), while the 
 * bonus represents the bonus value associated with the enhancement.
 */
struct Enchantment {
    /**
     * @brief The type of enhancement.
     */
    EnhancementType type;
    
    /**
     * @brief The bonus value associated with the enhancement.
     */
    int bonus;
};

#endif // ENCHANTMENT_H
