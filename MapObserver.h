#ifndef MAPOBSERVER_H
#define MAPOBSERVER_H

#include "Observer.h" // Include necessary header file(s)
#include "Map.h"

/**
 * @brief The MapObserver class represents an observer for map changes.
 * 
 * This class inherits from the Observer base class and is responsible for observing changes in a Map object.
 */
class MapObserver : public Observer {
public:
    /**
     * @brief Constructor for the MapObserver class.
     * 
     * @param map Pointer to the Map object to observe.
     */
    MapObserver(Map* map);

    /**
     * @brief Overridden update method.
     * 
     * This method is called when the observed map changes.
     */
    void update() override;

private:
    Map* map; // Pointer to the observed Map object.
};

#endif