#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "Observable.h"
#include <iostream>
#include <stdexcept>
#include <utility> // For std::swap
#include "characterCreator.h"
#include "Item.h"
#include <map> 
#include <array>


/**
 * @file map.h
 * @brief Header file for the Map class.
 * 
 * @details This file declares the Map class, which allows the generation of custom maps for a game.
 */

/**
 * @class Map
 * @brief Represents a custom map for a game.
 * 
 * @details The Map class provides functionality to create, modify, and validate custom maps.
 */

class characterCreator;

class Map: public Observable{
private:
    Cell** grid; /**< The grid representing the map. */
    int width; /**< The width of the map. */
    int height; /**< The height of the map. */
    int id;
    int chestsVisited;
    std::vector<ItemType> selectedPotions;
    std::map<std::array<int, 2>, characterCreator> characterMap;
    Logger* logger;

    /**
     * @brief Allocates memory for the grid.
     */
    void allocateGrid();

    /**
     * @brief Deallocates memory for the grid.
     */
    void deallocateGrid();

public:
    /**
     * @brief Constructs a new Map object with the specified width and height.
     * 
     * @param w The width of the map.
     * @param h The height of the map.
     */
    Map(int w, int h);

    void setLogger(Logger* log);

    /**
     * @brief Constructs a new Map object with the specified id, width, and height.
     * 
     * @param id The id of the map.
     * @param w The width of the map.
     * @param h The height of the map.
     */
    Map(int id, int w, int h);

    /**
     * @brief Destroys the Map object.
     */
    ~Map();

    // Copy constructor and copy assignment operator
    Map(const Map& other);
    Map& operator=(Map other);

    // Move constructor and move assignment operator
    Map(Map&& other) noexcept;
    Map& operator=(Map&& other) noexcept;

    /**
     * @brief Sets the type of a cell at the specified coordinates.
     * 
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     * @param type The type of the cell.
     * 
     * @throw std::out_of_range if the coordinates are out of bounds.
     */
    void setCell(int x, int y, CellType type);

    /**
     * @brief Gets the type of a cell at the specified coordinates.
     * 
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     * @return The type of the cell.
     * 
     * @throw std::out_of_range if the coordinates are out of bounds.
     */
    CellType getCellType(int x, int y) const;

    /**
     * @brief Checks if there is a clear path between two points on the map.
     * 
     * @param startX The x-coordinate of the starting point.
     * @param startY The y-coordinate of the starting point.
     * @param endX The x-coordinate of the ending point.
     * @param endY The y-coordinate of the ending point.
     * @return True if there is a clear path, false otherwise.
     */
    bool isPathClear(int startX, int startY, int endX, int endY) const;

    /**
     * @brief Gets the width of the map.
     * 
     * @return The width of the map.
     */
    int getWidth() const;

    /**
     * @brief Gets the height of the map.
     * 
     * @return The height of the map.
     */
    int getHeight() const;

    /**
     * @brief Sets the width of the map.
     * 
     * @param w The new width of the map.
     */
    void setWidth(int w);

    /**
     * @brief Sets the height of the map.
     * 
     * @param h The new height of the map.
     */
    void setHeight(int h);
    
    bool validateMap() const;

    int getId() const;


    /**
     * @brief Prints the map to the standard output.
     */
    void printMap() const;

    // Swap function to be used in copy assignment
    friend void swap(Map& first, Map& second) noexcept {
        using std::swap;
        swap(first.width, second.width);
        swap(first.height, second.height);
        swap(first.grid, second.grid);
    }

     /**
     * @brief Counts the number of opponents on the map.
     * 
     * @return The number of opponents.
     */
    int countOpponents() const;

    void moveCharacter(int x, int y, characterCreator& character);

    std::pair<int, int> findCharacter() const;

    static int mapCounter;

    bool canCharacterMoveToNextMap(int x, int y);

    bool isOpponentInRange(int range);

    void addItemToCharacterBackpack(characterCreator& character);

    void setSelectedPotions(const std::vector<ItemType>& potions);

    void setCharacters(const std::vector<std::pair<std::array<int, 2>, characterCreator>>& characters);

    /**
     * @brief Returns a vector of all coordinates of opponent cell types.
     * 
     * @return Vector of arrays representing coordinates of opponent cell types.
     */
    std::vector<std::array<int, 2>> getOpponentCoordinates() const;

    /**
     * @brief Gets the character at the specified coordinates.
     * 
     * @param x The x-coordinate of the character.
     * @param y The y-coordinate of the character.
     */
     characterCreator* getCharacterAtCoordinates(int x, int y);

     void deleteCharacterAtCoordinates(int x, int y);

};



#endif
