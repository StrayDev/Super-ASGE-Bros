#pragma once
#include <Engine/Sprite.h>
#include <Engine/Renderer.h>
#include "gameobject.h"

class TitleCard : public GameObject
{
public:
    TitleCard(ASGE::Renderer* renderer);
    ~TitleCard() = default;

private:
    std::string filePath = "data/tileset/titlebanner.png";

};


