#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include "Map.h" // Include necessary header file(s)

/**
 * @brief The MapBuilder class represents an abstract base class for building maps.
 * 
 * This class defines the interface for building maps, including a method to build the map
 * and a method to get the built map.
 */
class MapBuilder {
public:
    /**
     * @brief Destructor for the MapBuilder class.
     */
    virtual ~MapBuilder() {}

    /**
     * @brief Abstract method to build the map.
     * 
     * This method must be overridden by concrete subclasses to implement the map building logic.
     */
    virtual void buildMap() = 0;

    /**
     * @brief Abstract method to get the built map.
     * 
     * This method must be overridden by concrete subclasses to return the built map.
     * 
     * @return Pointer to the built map.
     */
    virtual Map* getMap() = 0;
};

#endif
