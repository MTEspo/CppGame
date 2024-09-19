#include "Map.h"
#include <vector>
#include <queue>
#include <random>
#include <ctime>
#include <cstdlib>
#include "Helmet.h"
#include "Weapon.h"
#include "Armor.h"
#include "Ring.h"
#include "Boots.h"
#include "Belt.h"
#include "Shield.h"
#include "StrengthPotion.h"
#include "HealthPotion.h"
#include "DexterityPotion.h"
#include "ConstitutionPotion.h"
#include "IntelligencePotion.h"
#include "WisdomPotion.h"
#include "CharismaPotion.h"
#include "ArmorClassPotion.h"
#include "AttackBonusPotion.h"
#include "DamageBonusPotion.h"

Map::Map(int w, int h) : width(w), height(h), grid(nullptr), chestsVisited(0) {
    allocateGrid();
    id = ++mapCounter;
    grid[0][0].setType(CellType::CHARACTER); 
    grid[h - 1][w - 1].setType(CellType::DOOR);
}

Map::~Map() {
    deallocateGrid();
}

Map::Map(int id, int w, int h) : id(id), width(w), height(h), grid(nullptr), chestsVisited(0) {
    allocateGrid();
}

Map::Map(const Map& other) : width(other.width), height(other.height), grid(nullptr), chestsVisited(other.chestsVisited), id(other.id) {
    allocateGrid();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j] = other.grid[i][j];
        }
    }
    id = ++mapCounter;
}

// Implementing copy-and-swap idiom
Map& Map::operator=(Map other) {
    swap(*this, other);
    return *this;
}

Map::Map(Map&& other) noexcept : grid(nullptr), width(0), height(0), chestsVisited(0) {
    swap(*this, other);
}

Map& Map::operator=(Map&& other) noexcept {
    swap(*this, other);
    return *this;
}

void Map::allocateGrid() {
    grid = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        grid[i] = new Cell[width];
    }
}

void Map::deallocateGrid() {
    for (int i = 0; i < height; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
    grid = nullptr; // Avoid dangling pointer
    width = height = 0;
}

void Map::setCell(int x, int y, CellType type) {
    if (x < 0 || y < 0 || x >= width || y >= height) {
        throw std::out_of_range("Coordinates are out of the map's bounds.");
    }
    if (type == CellType::CHARACTER && getCellType(x, y) == CellType::CHEST) {
        chestsVisited++;
    }
    grid[y][x].setType(type);
}

CellType Map::getCellType(int x, int y) const {
    return (x < 0 || y < 0 || x >= width || y >= height) ? CellType::WALL : grid[y][x].getType();
}


std::pair<int, int> Map::findCharacter() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (getCellType(x, y) == CellType::CHARACTER) {
                return std::make_pair(x, y);
            }
        }
    }
    return std::make_pair(-1, -1);
}

void Map::moveCharacter(int x, int y, characterCreator& character) {
    std::pair<int, int> characterPosition = findCharacter();
    int startX = characterPosition.first;
    int startY = characterPosition.second;

    int endX = startX + x;
    int endY = startY + y;

    //FIRST CHECK IF GUY WANTS TO GO INTO A DOOR, this would only be checked if the guy is trying to go into a door without getting the chest first
    if (getCellType(endX, endY) == CellType::DOOR) {
        std::cout << "You can't move onto the door without meeting the conditions." << std::endl;
        return;
    }

     if (getCellType(endX, endY) == CellType::CHEST) addItemToCharacterBackpack(character);

    if (isPathClear(startX, startY, endX, endY)) {
        setCell(endX, endY, CellType::CHARACTER);
        setCell(startX, startY, CellType::EMPTY);
        std::cout << "Character moved from (" << startX << "," << startY << ") to (" << endX << "," << endY << ")." << std::endl;
        logger->write("Characters coordinates-> X: "+std::to_string(endX)+" , Y: "+std::to_string(endY));
    } else {
        std::cout << "Path is blocked. Character cannot move from (" << startX << "," << startY << ") to (" << endX << "," << endY << ")." << std::endl;
    }
}


bool Map::isPathClear(int startX, int startY, int endX, int endY) const {
    if (getCellType(startX, startY) == CellType::WALL ||
        getCellType(endX, endY) == CellType::WALL ||
        getCellType(endX, endY) == CellType::OPPONENT) {
        return false;
    }

    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    std::queue<std::pair<int, int>> toVisit;

    toVisit.push({startX, startY});
    visited[startY][startX] = true;

    while (!toVisit.empty()) {
        std::pair<int, int> front = toVisit.front();
        int x = front.first;
        int y = front.second;
        toVisit.pop();

        if (x == endX && y == endY) {
            return true;
        }

        // Check all adjacent cells
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                // Only consider cells directly left, right, up, and down
                if (dx != 0 && dy != 0) continue;

                int newX = x + dx, newY = y + dy;

                // Check bounds and whether we've visited this cell already
                if (newX >= 0 && newX < width && newY >= 0 && newY < height && !visited[newY][newX]) {
                    visited[newY][newX] = true;
                    
                    // Check if it's not a wall
                    if (getCellType(newX, newY) != CellType::WALL) {
                        toVisit.push({newX, newY});
                    }
                }
            }
        }
    }

    return false;
}

bool Map::validateMap() const {
    int startX = 0;
    int startY = 0;
    int endX = width - 1;
    int endY = height - 1;

    if (getCellType(startX, startY) == CellType::WALL || getCellType(endX, endY) == CellType::WALL) {
        return false;
    }

    bool pathClear = isPathClear(startX, startY, endX, endY);
    bool chestExists = false;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (getCellType(x, y) == CellType::CHEST) {
                chestExists = true;
                break;
            }
        }
        if (chestExists) break;
    }
    return pathClear && chestExists;
}

void Map::printMap() const {
   
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            switch(grid[i][j].getType()) {
                case CellType::EMPTY: std::cout << " . "; break;
                case CellType::CHARACTER: std::cout << " C "; break;
                case CellType::OPPONENT: std::cout << " O "; break;
                case CellType::CHEST: std::cout << " $ "; break;
                case CellType::DOOR: std::cout << " D "; break;
                case CellType::WALL: std::cout << " W "; break;
                case CellType::ITEM: std::cout << " I "; break;
                default: std::cout << " ? "; break;
            }
        }
        std::cout << std::endl;
    }
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

// Setter methods
void Map::setWidth(int w) {
    width = w;
}

void Map::setHeight(int h) {
    height = h;
}

int Map::getId() const {
    return id;
}

int Map::mapCounter = 0;

bool Map::canCharacterMoveToNextMap(int x, int y) { //u pass in the coords of where the door is
    CellType cellAttemptedToMoveOnto = getCellType(x, y);
//std::cout << "SHOULD BE A DOOR: " << cellTypeToString(cellAttemptedToMoveOnto) << std::endl;
    if (cellAttemptedToMoveOnto == CellType::DOOR && chestsVisited > 0) {
        chestsVisited = 0; //reset the num of chests visited, so we can do the same thing for next map
        return true;
    }
    return false;
}

bool Map::isOpponentInRange(int range){
    std::pair<int, int> characterPosition = findCharacter();
    int startX = characterPosition.first;
    int startY = characterPosition.second;

    for (int i = -range; i <= range; i++) {
        for (int j = -range; j <= range; j++) {
            int checkX = startX + i;
            int checkY = startY + j;

            if (checkX >= 0 && checkX < width && checkY >= 0 && checkY < height) {
                if (getCellType(checkX, checkY) == CellType::OPPONENT) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Map::addItemToCharacterBackpack(characterCreator& character){
    std::vector<ItemType> armorTypes = {ItemType::HELMET, ItemType::ARMOR, ItemType::BOOTS, 
        ItemType::SHIELD, ItemType::BELT, ItemType::RING, ItemType::WEAPON};
        armorTypes.insert(armorTypes.end(), selectedPotions.begin(), selectedPotions.end());
        srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % armorTypes.size();
    ItemType selectedItemType = armorTypes[index];
    Item* item = nullptr;
    switch (selectedItemType) {
        case ItemType::HELMET:
            item = new Helmet(); 
            break;
        case ItemType::ARMOR:
            item = new Armor(); 
            break;
        case ItemType::BOOTS:
            item = new Boots(); 
            break;
        case ItemType::SHIELD:
            item = new Shield(); 
            break;
        case ItemType::BELT:
            item = new Belt(); 
            break;
        case ItemType::RING:
            item = new Ring(); 
            break;
        case ItemType::WEAPON:
            item = new Weapon(); 
            break;
        case ItemType::HEALTH_POTION:
            item = new HealthPotion(); 
            break;
        case ItemType::STRENGTH_POTION:
            item = new StrengthPotion(); 
            break;
        case ItemType::DEXTERITY_POTION:
            item = new DexterityPotion(); 
            break;
        case ItemType::CONSTITUTION_POTION:
            item = new ConstitutionPotion(); 
            break;
        case ItemType::INTELLIGENCE_POTION:
            item = new IntelligencePotion(); 
            break;
        case ItemType::WISDOM_POTION:
            item = new WisdomPotion(); 
            break;
        case ItemType::CHARISMA_POTION:
            item = new CharismaPotion(); 
            break;
        case ItemType::ARMOR_CLASS_POTION:
            item = new ArmorClassPotion(); 
            break;
        case ItemType::ATTACK_BONUS_POTION:
            item = new AttackBonusPotion(); 
            break;
        case ItemType::DAMAGE_BONUS_POTION:
            item = new DamageBonusPotion(); 
            break;

        default:
            std::cout << "Unknown item type." << std::endl;
            break;
    }



    // Add the created item to the character's backpack
    if (item) {
        character.openBackpack().addItem(item);
        logger->write( "Added " +item->itemTypeToString(selectedItemType) + " to backpack.");
    } else {
        std::cout << "Failed to create item." << std::endl;
    }




}

void Map::setSelectedPotions(const std::vector<ItemType>& potions) {
        selectedPotions = potions;
    }

int Map::countOpponents() const {
    int count = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (getCellType(j, i) == CellType::OPPONENT) {
                count++;
            }
        }
    }
    return count;
}

void Map::setCharacters(const std::vector<std::pair<std::array<int, 2>, characterCreator>>& characters) {
        for (const auto& entry : characters) {
            const auto& coordinates = entry.first;
            const auto& character = entry.second;
            characterMap.insert({coordinates, character});
        }
    }


std::vector<std::array<int, 2>> Map::getOpponentCoordinates() const {
    std::vector<std::array<int, 2>> opponentCoordinates;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (getCellType(x, y) == CellType::OPPONENT) {
                opponentCoordinates.push_back({x, y});
            }
        }
    }
    return opponentCoordinates;
}

characterCreator* Map::getCharacterAtCoordinates(int x, int y) {
    std::array<int, 2> coordinates = {x, y};
    
    auto it = characterMap.find(coordinates);
    
    if (it != characterMap.end()) {
        return &(it->second); 
    } else {
        throw std::runtime_error("No character found at the specified coordinates.");
    }
}

void Map::deleteCharacterAtCoordinates(int x, int y) {
    std::array<int, 2> coordinates = {x, y};
    
    auto it = characterMap.find(coordinates);
    
    if (it != characterMap.end()) {
        characterMap.erase(it);
    } else {
        throw std::runtime_error("No character found at the specified coordinates.");
    }
}

void Map::setLogger(Logger* log){
        this->logger = log;
    }



