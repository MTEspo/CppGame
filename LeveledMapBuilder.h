#ifndef LEVELEDMAPBUILDER_H
#define LEVELEDMAPBUILDER_H

#include "MapBuilder.h" // Include necessary header file(s)
#include <string>

/**
 * @brief The LeveledMapBuilder class represents a concrete builder for creating maps with level-specific adaptations.
 * 
 * It inherits from the MapBuilder class and implements the buildMap method to create maps
 * with specific adaptations based on the provided level.
 */
class LeveledMapBuilder : public MapBuilder {
private:
    Map* map; /**< Pointer to the map being built. */
    std::string filename; /**< Filename of the map file to load. */
    int level; /**< Level for which the map adaptations are made. */

public:
    /**
     * @brief Constructor for the LeveledMapBuilder class.
     * 
     * @param filename Filename of the map file to load.
     * @param level Level for which the map adaptations are made.
     */
    LeveledMapBuilder(const std::string& filename, int level);

    /**
     * @brief Method to build the map with level-specific adaptations.
     * 
     * Overrides the buildMap method of the base class (MapBuilder) to create maps
     * with specific adaptations based on the provided level.
     */
    void buildMap() override;

    /**
     * @brief Method to get the built map.
     * 
     * Overrides the getMap method of the base class (MapBuilder) to return the built map.
     * 
     * @return Pointer to the built map.
     */
    Map* getMap() override;

private:
    /**
     * @brief Method to adapt the map based on the provided level.
     * 
     * This method is called internally during map building to adapt the map based on the provided level.
     */
    void adaptMapToLevel();
};

#endif

