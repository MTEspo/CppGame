#ifndef CELLTYPE_H
#define CELLTYPE_H
#include <string>

enum class CellType {
    EMPTY,
    CHARACTER,
    OPPONENT,
    CHEST,
    DOOR,
    WALL,
    ITEM
};

std::string cellTypeToString(CellType cellType);

#endif