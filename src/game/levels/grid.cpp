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
            _cells.push_back(new Cell(position));

        }
    }
}

Cell *Grid::getCell(Vector2 pos)
{
    float least_distance = 10000.0f; //arbitrary high number
    Cell* closest_obj;

    for(auto c : _cells)
    {
        auto distance = Vector2::distance(pos, c->getPosition());
        if ( distance < least_distance )
        {
            least_distance = distance;
            closest_obj = c;
        }
    }
    return closest_obj;
}
