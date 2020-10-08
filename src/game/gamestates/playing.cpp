#include <game/gameobjects/entities/player/mario.h>
#include "playing.h"
#include "game/gameobjects/blocks/block.h"
#include "game/levels/leveldata.h"

Playing::~Playing()
{
    delete _grid;
}

void Playing::init(ASGE::Renderer *renderer)
{
    /// level
    auto level_data = LevelData();
    auto dimensions = Vector2(32, 16);
    _grid = new Grid(dimensions, 1096 / 16);
    ///added additional pixel to remove gap 1080 -> 1096 due to some sort of loss

    for(auto i = 0; i < _grid->Cells().size(); i++)
    {
        if (level_data.blocks[i] == 0) continue;

        auto block = new Block(renderer, level_data.blocks[i]);
        block->setSize(_grid->cellSize());
        block->setPosition(_grid->getCell(i));

        GameObjects.push_back(block);

        if (i == level_data.blocks.size()) return; ///safety
    }

    ///player
    auto mario = new Mario(renderer);
    GameObjects.push_back(mario);
    Entities.push_back(mario);
}

void Playing::update(float delta_time)
{
    for(auto e: Entities)
    {
        e->update(delta_time);
    }
}

