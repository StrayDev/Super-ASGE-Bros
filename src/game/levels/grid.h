#pragma once
#include <vector>
#include <game/math/vector2.h>
#include "cell.h"

class Grid
{
public:
    Grid() = default;
    Grid(Vector2 _gridsize, float _cellsize);
    ~Grid() = default;

    std::vector<Cell*> allCells() { return _cells; }
    Cell* getCell(Vector2 pos);

    float getCellSize() const { return cell_size; }
    Vector2 getGridSize() const { return grid_size; }

private:
    Vector2 grid_size;
    float cell_size;
    std::vector<Cell*> _cells;
};


