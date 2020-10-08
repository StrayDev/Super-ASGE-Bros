#pragma once
#include <vector>
#include <game/math/vector2.h>

class Grid
{
public:
    Grid() = default;
    Grid(Vector2 gridSize, float cellSize);
    ~Grid() = default;

    std::vector<Vector2> Cells() { return _cells; }
    Vector2 getCell(int i) { return _cells[i]; }
    float cellSize() const { return _cellSize; }

private:
    Vector2 _gridSize;
    float _cellSize;
    std::vector<Vector2> _cells;
};


