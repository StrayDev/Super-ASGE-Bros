#pragma once
#include "game/gameobjects/gameobject.h"
#include "factory.h"

class BlockFactory : public Factory
{
public:
    static GameObject* createBlock(int i);

private:
};


