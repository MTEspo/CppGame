#ifndef ITEM_H
#define ITEM_H

#include "ItemType.h"
#include "Enchantment.h"
#include <cstdlib>
#include <string> // Include for std::string

/**
 * <cstdlib> was used for generating random numbers, this is useful in the 
 * implementations of generating random enchantment levels for the child classes of 
 * the Item class.
 */

/**
 * @file Item.h
 * @brief Header file for the Item class.
 * 
 * @details This file declares the Item class, which represents a generic item in the game.
 * Items can have different types and enchantments that provide various enhancements to
 * characters' attributes or abilities.
 */

/**
 * @class Item
 * @brief Represents a generic item in the game.
 * 
 * @details The Item class represents a generic item that can be found or used by characters
 * in the game. Each item has a type (such as helmet, ring, weapon, etc.) and may have an
 * associated enchantment that enhances the character's attributes or abilities.
 */
class Item {
private:
    ItemType type; /**< The type of the item. */
    Enchantment enchantment; /**< The enchantment associated with the item. */

public:
    /**
     * @brief Constructor for the Item class.
     * 
     * @param itemType The type of the item to be created.
     */
    Item(ItemType itemType);

    /**
     * @brief Sets the enchantment for the item.
     * 
     * @param newEnchantment The enchantment to be set for the item.
     */
    void setEnchantment(const Enchantment& newEnchantment);

    /**
     * @brief Gets the type of the item.
     * 
     * @return The type of the item.
     */
    ItemType getType() const;

    /**
     * @brief Gets the enchantment associated with the item.
     * 
     * @return The enchantment associated with the item.
     */
    Enchantment getEnchantment() const;

    /**
     * @brief Converts an EnhancementType to its string representation.
     * 
     * @param type The EnhancementType to be converted.
     * @return The string representation of the EnhancementType.
     */
    static std::string enchantmentTitle(EnhancementType type);

    /**
     * @brief Converts an ItemType to its string representation.
     * 
     * @param type The ItemType to be converted.
     * @return The string representation of the ItemType.
     */
    static std::string itemTypeToString(ItemType type);
};

#endif