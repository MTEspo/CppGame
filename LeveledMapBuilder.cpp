#include "LeveledMapBuilder.h"
#include "MapEditor.h"
#include <stdexcept>

LeveledMapBuilder::LeveledMapBuilder(const std::string& filename, int level) : map(nullptr), filename(filename), level(level) {}

void LeveledMapBuilder::buildMap() {
    map = MapEditor::loadMapFromFile(filename);
    if (!map) {
        throw std::runtime_error("Failed to load map from file.");
    }
    adaptMapToLevel();
}

Map* LeveledMapBuilder::getMap() {
    return map;
}

void LeveledMapBuilder::adaptMapToLevel() {
    int numOpponents = level;
    int currentOpponents = 0;


    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            if (map->getCellType(x, y) == CellType::OPPONENT) {
                ++currentOpponents;
            }
        }
    }

    if (currentOpponents > numOpponents) {
        int opponentsToRemove = currentOpponents - numOpponents;
        for (int y = 0; y < map->getHeight(); ++y) {
            for (int x = 0; x < map->getWidth(); ++x) {
                if (map->getCellType(x, y) == CellType::OPPONENT && opponentsToRemove > 0) {
                    map->setCell(x, y, CellType::EMPTY);
                    --opponentsToRemove;
                }
            }
        }
    } else if (currentOpponents < numOpponents) {
        int opponentsToAdd = numOpponents - currentOpponents;
        for (int i = 0; i < opponentsToAdd; ++i) {
            int opponentX = rand() % map->getWidth();
            int opponentY = rand() % map->getHeight();
            if (map->getCellType(opponentX, opponentY) == CellType::EMPTY) {
                map->setCell(opponentX, opponentY, CellType::OPPONENT);
            } else {
                --i;
            }
        }
    }
}

