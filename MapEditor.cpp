
#include <fstream>
#include <iostream>
#include "MapEditor.h"
#include <limits>




Map* MapEditor::createNewMap() {
    int width, height;
    std::cout << "Enter map width: ";
    std::cin >> width;
    std::cout << "Enter map height: ";
    std::cin >> height;

    Map* gameMap = new Map(width, height);
    std::cout << "\nWARNING: Valid maps must have a clear path from the character to the door and at least one chest.\n\n";

    gameMap->printMap();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if ((x == 0 && y == 0) || (x == width - 1 && y == height - 1)) {
                continue;
            }

            int cellTypeInput;
            bool validInput = false;
            while (!validInput) {
                std::cout << "\nSet cell (" << x << "," << y << ") type (0:EMPTY, 2:OPPONENT, 3:CHEST, 5:WALL): ";
                std::cin >> cellTypeInput;

                if (std::cin.fail() || (cellTypeInput != 0 && cellTypeInput != 2 && cellTypeInput != 3 && cellTypeInput != 5)) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                
                validInput = true;
                gameMap->setCell(x, y, static_cast<CellType>(cellTypeInput));
            }
            std::cout<<"\n";
            gameMap->printMap();
            std::cout<<"\n";
        }
    }

    if (gameMap->validateMap()) {
        std::cout << "Map created successfully." << std::endl;
        return gameMap;
    } else {
        std::cout << "Map is not valid, it either does not have a clear path OR a chest is not present in the map." << std::endl;
        delete gameMap;
        return nullptr;
    }
}

void MapEditor::editMap() {
    std::string filename;
    std::cout << "Enter the filename of the map you want to edit: ";
    std::cin >> filename;

    Map* map = loadMapFromFile(filename);
    if (!map) {
        std::cerr << "Failed to load map for editing." << std::endl;
        return;
    }

    map->printMap();

    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            if ((x == 0 && y == 0) || (x == map->getWidth() - 1 && y == map->getHeight() - 1)) {
                continue;
            }

            int cellTypeInput;
            bool validInput = false;
            while (!validInput) {
                std::cout << "\nEdit cell (" << x << "," << y << ") type (0:EMPTY, 2:OPPONENT, 3:CHEST, 5:WALL): ";
                std::cin >> cellTypeInput;

                if (std::cin.fail() || (cellTypeInput != 0 && cellTypeInput != 2 && cellTypeInput != 3 && cellTypeInput != 5)) {
                    std::cout << "Invalid input. Please try again." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                validInput = true;
                map->setCell(x, y, static_cast<CellType>(cellTypeInput));
                map->printMap();
            }
        }
    }

    if (map->validateMap()) {
        std::cout << "Enter filename to save the edited map: ";
        std::cin >> filename;
        saveMapToFile(filename, map);
    } else {
        std::cout << "Edited map does not have a valid path, and cannot be saved." << std::endl;
    }

    delete map; // Clean up
}

bool MapEditor::saveMapToFile(const std::string& filename, const Map* map) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return false;
    }

    outputFile << map->getId() << " " << map->getWidth() << " " << map->getHeight() << std::endl;

    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            switch(map->getCellType(x, y)) {
                case CellType::EMPTY: outputFile << "."; break;
                case CellType::CHARACTER: outputFile << "C"; break;
                case CellType::OPPONENT: outputFile << "O"; break;
                case CellType::CHEST: outputFile << "$"; break;
                case CellType::DOOR: outputFile << "D"; break;
                case CellType::WALL: outputFile << "W"; break;
                case CellType::ITEM: outputFile << "I"; break;
                default: outputFile << "?"; break;
            }
        }
        outputFile << std::endl;
    }

    outputFile.close();
    std::cout << "Map saved to file: " << filename << std::endl;
    return true;
}

Map* MapEditor::loadMapFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return nullptr;
    }

    int id, width, height;
    inputFile >> id >> width >> height;

    Map* map = new Map(id, width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char cellType;
            inputFile >> cellType;
            switch (cellType) {
                case '.': map->setCell(x, y, CellType::EMPTY); break;
                case 'C': map->setCell(x, y, CellType::CHARACTER); break;
                case 'O': map->setCell(x, y, CellType::OPPONENT); break;
                case '$': map->setCell(x, y, CellType::CHEST); break;
                case 'D': map->setCell(x, y, CellType::DOOR); break;
                case 'W': map->setCell(x, y, CellType::WALL); break;
                case 'I': map->setCell(x, y, CellType::ITEM); break;
                default: 
                    std::cerr << "Warning: Unknown cell type '" << cellType << "' encountered." << std::endl;
                    break;
            }
        }
    }

    inputFile.close();
    std::cout << "Map loaded from file: " << filename << std::endl;
    return map;
}


void MapEditor::addMapToCampaign(Campaign& campaign, Map* map) {
    campaign.addMap(map);
}

bool MapEditor::saveCampaignToFile(const std::string& filename, const Campaign* campaign) {
    std::ofstream outputFile("campaign/"+filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return false;
    }
    outputFile << campaign->getId() << " ";
    for (const auto& map : campaign->getMaps()) {
        outputFile << map->getId() << " ";
    }
    outputFile << std::endl;

    outputFile.close();
    std::cout << "Campaign saved to file: " << filename << std::endl;

    for (const auto& map : campaign->getMaps()) {
        std::string mapFilename = "maps/"+filename+"_map_" + std::to_string(map->getId());
        if (!saveMapToFile(mapFilename, map)) {
            return false;
        }
    }

    return true;
}

Campaign* MapEditor::loadCampaign(const std::string& filename) {
    std::ifstream inputFile("campaign/"+filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
        return nullptr;
    }
    
    int campaignId;
    inputFile >> campaignId;
    
    Campaign* campaign = new Campaign(campaignId);
    
    int mapId;
    while (inputFile >> mapId) {
        std::string mapFilename = "maps/"+filename + "_map_" + std::to_string(mapId);
        std::cout<<mapFilename;
        Map* map = loadMapFromFile(mapFilename);
        if (map) {
            campaign->addMap(map);
        } else {
            std::cerr << "Error loading map " << mapFilename << ". Skipping." << std::endl;
        }
    }
    
    inputFile.close();
    std::cout << "Campaign loaded from file: " << filename << std::endl;
    
    return campaign;
}

