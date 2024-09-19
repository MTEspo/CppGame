#include "campaign.h"
#include <algorithm>
#include "MapEditor.h"


Campaign::Campaign() {
    id = ++campaignCounter;
}

Campaign::Campaign(int campaignId) : id(campaignId) {
}

Campaign::~Campaign() {
    for (Map* map : maps) {
        delete map;
    }
}

void Campaign::addMap(Map* map) {
    maps.push_back(map);
}
int Campaign::getId() const {
    return id;
}
std::vector<Map*> Campaign::getMaps() const {
    return maps;
}

int Campaign::campaignCounter = 0;

Map* Campaign::getCurrentMap() const {
    if (maps.empty()) {
        return nullptr; // NO MORE MAPS BROTHER
    }
    return maps.front(); //RETURNS FIRST MAP WHICH WOULD BE CURRENT MAP IN CAMPAIGN
}

Map* Campaign::getNextMap() {
    if (maps.empty()) {
        return nullptr; 
    }

    Map* currentMap = maps.front();
    delete currentMap;
    maps.erase(maps.begin());

    if (!maps.empty()) {
        std::cout << "LOADING NEXT MAP";
        std::cout << std::endl;
        maps.front()->printMap();
        return maps.front();
    } else {
        return nullptr; // No maps left after deletion
    }
}

 void Campaign::createUserCampaign(){
    Campaign newCampaign;
    MapEditor mapEditor;
    int numberOfMaps;

    std::cout << "Enter the number of maps for your campaign: ";
    std::cin >> numberOfMaps;

    for (int i = 0 ; i < numberOfMaps ; i++){
        std::cout << "Creating map " << (i + 1) << " of " << numberOfMaps << std::endl;
        Map* newMap = mapEditor.createNewMap(); //this now returns a pointer to the map instead of void
        if (newMap) newCampaign.addMap(newMap);
        else {
            std::cerr<<"Exiting now.";
            return;
        }
    }

    std::string campaignFileName;
    std::cout << "Enter a name for your campaign file: ";
    std::cin >> campaignFileName;
    campaignFileName = "campaign_"+campaignFileName;

    if (mapEditor.saveCampaignToFile(campaignFileName, &newCampaign)) std::cout << "Saved campaign successfully to the file" << campaignFileName << std::endl;
    else std::cerr << "Failed to save the campaign." << std::endl;
}

Campaign* Campaign::loadUserCreatedCampaign(){
    std::cout << "Enter the filename of the campaign you want to load: ";
    std::string userFileName;
    std::cin >> userFileName;
    std::string fullFileName = "campaign_" + userFileName;
    MapEditor editor;
    Campaign* loadedCampaign = editor.loadCampaign(fullFileName);
    return loadedCampaign;
}

// void Campaign::connectMaps(Map* map1, Map* map2) {
//     // Ensure map1 and map2 are not already connected
//     if (std::find(map1->connectedMaps.begin(), map1->connectedMaps.end(), map2) == map1->connectedMaps.end()) {
//         map1->connectedMaps.push_back(map2);
//     }

//     // Ensure map2 and map1 are not already connected (assuming bidirectional connections)
//     if (std::find(map2->connectedMaps.begin(), map2->connectedMaps.end(), map1) == map2->connectedMaps.end()) {
//         map2->connectedMaps.push_back(map1);
//     }
//}


