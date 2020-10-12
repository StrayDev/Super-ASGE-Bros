#include "Engine/Logger.hpp"
#include "savesystem.h"


void FileSystem::loadLevel(const std::string& level_id, ASGE::Renderer* renderer)
{
    auto file = new std::ifstream();
    file->open("D:/ASGE Projects/Super-ASGE-Bros/data/level/level_" + level_id + ".txt");
    ///how do i do this relative to the project directory?

    ///run delete on all static vectors - delete does the checks automatically

    if (!file->is_open())
    {
        Logging::log("ERROR : Level did not load\n");
        return;
    }

    std::string line;
    std::getline( *file, line, ':');


    auto grid = loadGrid(file);
    loadBlocks(file, grid, renderer);
    /// loadEntities - player, enemies, warp pipes and load zones

    file->close();
    delete file;
}

Grid* FileSystem::loadGrid(std::ifstream* file)
{
    std::string line;
    int x;
    *file >> x;

    std::getline( *file, line, ':');
    int y;
    *file >> y;

    //additional 6 pixels remove white lines between blocks, may need to scale with resolution
    float screen_height = 1080 + 8; //this will need to be divisible by 16... i think
    auto cell_size = screen_height / 16;
    return new Grid(Vector2(x, y), cell_size);
}

void FileSystem::loadBlocks(std::ifstream* file, Grid* grid, ASGE::Renderer* renderer)
{
    std::string line;
    std::getline( *file, line );

    for(int y = 0; y < grid->getGridSize().y(); y++)
    {
        std::getline( *file, line, ':');

        for(int x = 0; x < grid->getGridSize().x(); x++)
        {
            auto i = 0;
            file->get();
            *file >> i;
            Logging::log(std::to_string(i) + ",");

            if(i == 0)
            {
                ///pass the cell into the grid;
                continue;
            }

            auto gameobject = new GameObject();
            auto cell_position = Vector2(x * grid->getCellSize(), y * grid->getCellSize() );
            auto cell = grid->getCell(cell_position);
            auto sprite = new SpriteRenderer();
            auto dimensions = grid->getCellSize();

            sprite->createSprite(renderer, "data/tileset/ground.png");
            sprite->setSpriteSize(Vector2(dimensions, dimensions));
            gameobject->addComponent(sprite);

            cell->assignToCell(1, gameobject);
            //gameobject->getComponent<Transform*>()->setPosition( cell->getPosition() );
            Logging::log(std::to_string(cell->getPosition().x()) + ", ");
            Logging::log(std::to_string(cell->getPosition().x())+ "\n");
        }
        *file >> std::ws;
    }
}
