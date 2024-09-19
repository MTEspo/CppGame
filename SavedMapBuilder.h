#ifndef SAVEDMAPBUILDER_H
#define SAVEDMAPBUILDER_H

#include "MapBuilder.h"
#include <string>

/**
 * @brief The SavedMapBuilder class is responsible for building a map by loading it from a saved file.
 * 
 * This class inherits from the MapBuilder interface and implements the buildMap method to construct a map
 * by loading it from a specified file.
 */
class SavedMapBuilder : public MapBuilder {
private:
    Map* map; ///< Pointer to the constructed map.
    std::string filename; ///< The filename from which the map will be loaded.

public:
    /**
     * @brief Constructor for SavedMapBuilder.
     * 
     * @param filename The filename of the saved map to be loaded.
     */
    SavedMapBuilder(const std::string& filename);

    /**
     * @brief Builds the map by loading it from the specified file.
     * 
     * This method loads the map from the specified file and constructs it.
     */
    void buildMap() override;

    /**
     * @brief Returns the constructed map.
     * 
     * @return A pointer to the constructed map.
     */
    Map* getMap() override;
};

#endif // SAVEDMAPBUILDER_H

