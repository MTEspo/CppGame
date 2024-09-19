#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "map.h"
#include "campaign.h"
#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief The MapEditor class provides functionality for creating, editing, and saving maps and campaigns.
 */
class MapEditor {
public:
    /**
     * @brief Creates a new map.
     */
    static Map* createNewMap();

    /**
     * @brief Edits an existing map.
     * 
     * @param map A pointer to the map to be edited.
     * @return The edited map.
     */
    static Map* loadMapFromFile(const std::string& filename);

    /**
     * @brief Saves a map to a file.
     * 
     * @param filename The name of the file to save the map to.
     * @param map A pointer to the map to be saved.
     * @return True if the map was successfully saved, false otherwise.
     */
    static bool saveMapToFile(const std::string& filename, const Map* map);

    /**
     * @brief Adds a map to a campaign.
     * 
     * @param campaign The campaign to add the map to.
     * @param map A pointer to the map to be added.
     */
    static void addMapToCampaign(Campaign& campaign, Map* map);

    /**
     * @brief Saves a campaign to a file.
     * 
     * @param filename The name of the file to save the campaign to.
     * @param campaign A pointer to the campaign to be saved.
     * @return True if the campaign was successfully saved, false otherwise.
     */
    static bool saveCampaignToFile(const std::string& filename, const Campaign* campaign);

    /**
     * @brief Loads a campaign from a file.
     * 
     * @param filename The name of the file containing the campaign data.
     * @return A pointer to the loaded campaign.
     */
    static Campaign* loadCampaign(const std::string& filename);

    /**
     * @brief Allows editing of a map.
     * 
     * This member function is not static as it operates on the instance of the MapEditor class.
     */
    static void editMap();
};

#endif