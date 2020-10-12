#include "grid.h"

Grid::Grid(Vector2 _gridsize, float _cellsize)
{
    grid_size = _gridsize;
    cell_size = _cellsize;

    for (int y = 0; y < (int)_gridsize.y(); y++)
    {
        for (int x = 0; x < (int)_gridsize.x(); x++)
        {
            auto position = Vector2((float)x * _cellsize, (float)y * _cellsize);
            _cells.push_back(new Cell(cell_size, position));

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
