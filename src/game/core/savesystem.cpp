#include "Engine/Logger.hpp"
#include "savesystem.h"


void FileSystem::loadLevel(const std::string& level_id, ASGE::Renderer* renderer)
{
    auto file = new std::ifstream();
    file->open("D:/ASGE Projects/Super-ASGE-Bros/data/level/level_" + level_id + ".txt");
    //how do i do this relative to the project directory?

    ///run delete on all static vectors

    if (!file->is_open())
    {
        Logging::log("ERROR : Level did not load\n");
        return;
    }

    std::string line;
    std::getline( *file, line, ':');


    auto grid = loadGridFrom(file);
    loadBlocksFrom(file, grid, renderer);
    /// loadEntities - player, enemies, warp pipes and load zones

    file->close();
    delete file; ///is this needed?
}

Grid* FileSystem::loadGridFrom(std::ifstream* file)
{
    std::string line;
    int x;
    *file >> x;

    std::getline( *file, line, ':');
    int y;
    *file >> y;

    auto screen_height = 1080 + 16; //seem to lose 16 pixels somewhere
    auto cell_size = screen_height / 16;
    return new Grid(Vector2(x, y), cell_size);
}

void FileSystem::loadBlocksFrom(std::ifstream* file, Grid* grid, ASGE::Renderer* renderer)
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
                Logging::log("\n");
                continue;
            }

            auto gameobject = new GameObject();
            auto cell = grid->getCell(x + (y * grid->getGridSize().x()));
            auto sprite = new SpriteRenderer();
            auto dimensions = grid->getCellSize();

            sprite->createSprite(renderer, "data/tileset/ground.png");
            sprite->setSpriteSize(Vector2(dimensions, dimensions));
            gameobject->addComponent(sprite);

            Vector2 pos(cell.x() * grid->getCellSize(), cell.x() * grid->getCellSize());
            gameobject->getComponent<Transform*>()->setPosition( cell );
            Logging::log(std::to_string(cell.x()) + ", ");
            Logging::log(std::to_string(cell.y())+ "\n");
        }
        *file >> std::ws;
    }
}
