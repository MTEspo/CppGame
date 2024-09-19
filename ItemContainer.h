#ifndef ITEM_CONTAINER_H
#define ITEM_CONTAINER_H

#include "Item.h"
#include <vector>

/**
 * @file ItemContainer.h
 * @brief Header file for the ItemContainer class.
 * 
 * @details This file declares the ItemContainer class, which represents a container
 * for holding items in the game.
 */

/**
 * @class ItemContainer
 * @brief Represents a container for holding items in the game.
 * 
 * @details The ItemContainer class provides functionality to add items, retrieve items
 * by index, get the total count of items, and get a vector of all items in the container.
 */
class ItemContainer {
private:
    std::vector<Item*> items; /**< Vector to store pointers to items. */
    int count = 0; /**< Total count of items in the container. */

public:
    /**
     * @brief Adds an item to the container.
     * 
     * @param item Pointer to the item to be added.
     */
    void addItem(Item* item);

    /**
     * @brief Removes an item from the container by index.
     * 
     * @param index Index of the item to remove.
     * @return Pointer to the removed item, or nullptr if index is out of bounds.
     */
    Item* removeItem(int index);

    /**
     * @brief Checks if the container is empty.
     * 
     * @return True if the container is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Retrieves an item from the container by index.
     * 
     * @param index Index of the item to retrieve.
     * @return Pointer to the item at the specified index, or nullptr if index is out of bounds.
     */
    Item* getItem(int index) const;

    /**
     * @brief Gets the size of the container.
     * 
     * @return The size of the container.
     */
    int size() const;

    /**
     * @brief Gets the total count of items in the container.
     * 
     * @return The total count of items in the container.
     */
    int getItemCount();

    /**
     * @brief Gets a constant reference to the vector of items in the container.
     * 
     * @return A constant reference to the vector of items.
     */
    const std::vector<Item*>& getItems() const;
    void showItemList();
};

#endif // ITEM_CONTAINER_H
