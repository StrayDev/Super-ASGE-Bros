#pragma once
#include <vector>
#include <game/math/vector2.h>

class Grid
{
public:
    Grid() = default;
    Grid(Vector2 gridSize, float cellSize);
    ~Grid() = default;

    std::vector<Vector2> allCells() { return _cells; }
    Vector2 getCell(int i) { return _cells[i]; }
    float getCellSize() const { return cell_size; }
    Vector2 getGridSize() const { return grid_size; }

private:
    Vector2 grid_size;
    float cell_size;
    std::vector<Vector2> _cells;
};


