#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "game/levels/grid.h"
#include "game/gameobjects/gameobject.h"
#include "game/components/spriterenderer.h"
#include <game/components/transform.h>

class FileSystem
{
public:
    static void loadLevel(const std::string& level_id, ASGE::Renderer* renderer);

private:
    static Grid* loadGridFrom(std::ifstream* file);
    static void loadBlocksFrom(std::ifstream* file, Grid* grid, ASGE::Renderer* renderer);
};


