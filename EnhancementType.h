#ifndef ENHANCEMENTTYPE_H
#define ENHANCEMENTTYPE_H

/**
 * @file EnhancementType.h
 * @brief Header file defining the EnhancementType enum class.
 * 
 * @details This file defines the EnhancementType enum class, which represents 
 * various types of enhancements that can be applied to items in the game.
 */

/**
 * @brief Enumeration representing different types of enhancements.
 * 
 * @details The EnhancementType enum class represents different types of 
 * enhancements that can be applied to items in the game. Each enhancement type 
 * corresponds to a specific attribute or property of the item, such as strength, 
 * dexterity, constitution, intelligence, wisdom, charisma, armor class, or attack damage.
 */
enum class EnhancementType {
    STRENGTH,       ///< Represents the enhancement type for strength.
    DEXTERITY,      ///< Represents the enhancement type for dexterity.
    CONSTITUTION,   ///< Represents the enhancement type for constitution.
    INTELLIGENCE,   ///< Represents the enhancement type for intelligence.
    WISDOM,         ///< Represents the enhancement type for wisdom.
    CHARISMA,       ///< Represents the enhancement type for charisma.
    ARMOR_CLASS,   
    ATTACK_BONUS,   
    DAMAGE_BONUS,   
    HEALTH
};

#endif 

