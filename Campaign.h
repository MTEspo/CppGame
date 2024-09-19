#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "map.h" // Include necessary header file(s)
#include <vector>

/**
 * @brief The Campaign class represents a collection of maps.
 * 
 * It allows adding maps to a campaign and retrieving information about the campaign.
 * Each campaign has a unique identifier.
 */
class Campaign {
private:
    std::vector<Map*> maps; /**< A vector to store pointers to maps in the campaign. */
    int id; /**< The unique identifier of the campaign. */

public:
    /**
     * @brief Default constructor for the Campaign class.
     * 
     * Initializes the campaign with an automatically generated ID.
     */
    Campaign();

    /**
     * @brief Parameterized constructor for the Campaign class.
     * 
     * Initializes the campaign with the given ID.
     * 
     * @param campaignId The unique identifier for the campaign.
     */
    Campaign(int campaignId);

    /**
     * @brief Destructor for the Campaign class.
     * 
     * Deallocates memory for all maps stored in the campaign.
     */
    ~Campaign();

    /**
     * @brief Adds a map to the campaign.
     * 
     * @param map Pointer to the map to be added.
     */
    void addMap(Map* map);

    //void connectMaps(Map* map1, Map* map2); // Currently commented out

    /**
     * @brief Getter method to retrieve the unique identifier of the campaign.
     * 
     * @return The unique identifier of the campaign.
     */
    int getId() const;

    /**
     * @brief Getter method to retrieve the vector of maps in the campaign.
     * 
     * @return A vector containing pointers to all maps in the campaign.
     */
    std::vector<Map*> getMaps() const;

    static int campaignCounter; /**< Static counter to generate unique IDs for campaigns. */

    Map* getNextMap();
    Map* getCurrentMap() const;

    static void createUserCampaign();
    static Campaign* loadUserCreatedCampaign();

};

#endif
