#include "cell.h"
#include "CellType.h"


Cell::Cell() : type(CellType::EMPTY) {}

void Cell::setType(CellType newType) {
    type = newType;
}

CellType Cell::getType() const {
    return type;
}

std::string cellTypeToString(CellType cellType) {
    switch (cellType) {
        case CellType::EMPTY: return "EMPTY";
        case CellType::CHARACTER: return "CHARACTER";
        case CellType::OPPONENT: return "OPPONENT";
        case CellType::CHEST: return "CHEST";
        case CellType::DOOR: return "DOOR";
        case CellType::WALL: return "WALL";
        case CellType::ITEM: return "ITEM";
        default: return "UNKNOWN";
    }
}

