#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "game/levels/grid.h"
#include "game/gameobjects/gameobject.h"
#include "game/components/spriterenderer.h"
#include <game/objectfactories/blockfactory.h>

class FileSystem
{
public:
    static void loadLevel(const std::string& level_id, ASGE::Renderer* renderer);

private:
    static Grid* loadGrid(std::ifstream* file);
    static void loadBlocks(std::ifstream* file, Grid* grid, ASGE::Renderer* renderer);
};


