#ifndef CELL_H
#define CELL_H

#include "CellType.h"

class Cell {
private:
    CellType type;
    
public:
    Cell();
    void setType(CellType newType);
    CellType getType() const;
};

#endif