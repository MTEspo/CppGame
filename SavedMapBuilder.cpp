#include "SavedMapBuilder.h"
#include "MapEditor.h"
#include <stdexcept>

SavedMapBuilder::SavedMapBuilder(const std::string& filename) : map(nullptr), filename(filename) {}

void SavedMapBuilder::buildMap() {
    map = MapEditor::loadMapFromFile(filename);
    if (!map) {
        throw std::runtime_error("Failed to load map from file.");
    }
}

Map* SavedMapBuilder::getMap() {
    return map;
}
