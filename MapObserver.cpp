#include "MapObserver.h"
#include <iostream>

MapObserver::MapObserver(Map* map) {
    this->map = map;
}

void MapObserver::update() {
    std::cout << "Map view updated:\n";
    map->printMap();
}


