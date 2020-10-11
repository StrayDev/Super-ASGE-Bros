#include "grid.h"

Grid::Grid(Vector2 gridSize, float cellSize)
{
    grid_size = gridSize;
    cell_size = cellSize;

    for (int y = 0; y < (int)gridSize.y(); y++)
    {
        for (int x = 0; x < (int)gridSize.x(); x++)
        {
            auto position = Vector2((float)x * cellSize, (float)y * cellSize);
            _cells.push_back(position);
        }
    }
}
