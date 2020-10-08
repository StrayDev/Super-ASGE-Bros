#pragma once
#include <Engine/Sprite.h>
#include <Engine/Renderer.h>
#include "gameobject.h"

class Tile : public GameObject
{
public:
    Tile(ASGE::Renderer* renderer);
    ~Tile() = default;

private:
    std::string filePath = "data/tileset/ground.png";
};


