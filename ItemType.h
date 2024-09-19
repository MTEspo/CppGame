#ifndef ITEMTYPE_H
#define ITEMTYPE_H

/**
 * @file ItemType.h
 * @brief Header file for the ItemType enum class.
 * 
 * @details This file declares the ItemType enum class, which represents the different types of items in the game.
 */

/**
 * @enum ItemType
 * @brief Represents the different types of items in the game.
 * 
 * @details The ItemType enum class defines constants for various types of items that can be used in the game,
 * such as HELMET, RING, WEAPON, SHIELD, ARMOR, and BOOTS.
 */
enum class ItemType {
    HELMET, /**< Represents a helmet item. */
    RING, /**< Represents a ring item. */
    WEAPON, /**< Represents a weapon item. */
    SHIELD, /**< Represents a shield item. */
    ARMOR, /**< Represents an armor item. */
    BOOTS, /**< Represents a boots item. */
    BELT,
    HEALTH_POTION,  /**< Represents a health potion item. */
    STRENGTH_POTION,/**< Represents a strength potion item. */
    DEXTERITY_POTION,/**< Represents a dexterity potion item. */
    CONSTITUTION_POTION,/**< Represents a constitution potion item. */
    INTELLIGENCE_POTION,/**< Represents an intelligence potion item. */
    WISDOM_POTION,  /**< Represents a wisdom potion item. */
    CHARISMA_POTION,/**< Represents a charisma potion item. */
    ARMOR_CLASS_POTION,/**< Represents an armor class potion item. */
    ATTACK_BONUS_POTION,/**< Represents an attack bonus potion item. */
    DAMAGE_BONUS_POTION
};

#endif // ITEMTYPE_H

