#include "grid.h"

Grid::Grid(Vector2 gridSize, float cellSize)
{
    _gridSize = gridSize;
    _cellSize = cellSize;

    for (int y = 0; y < (int)_gridSize.y(); y++)
    {
        for (int x = 0; x < (int)_gridSize.x(); x++)
        {
            auto position = Vector2((float)x * _cellSize, (float)y * _cellSize);
            _cells.push_back(position);
        }
    }
}
