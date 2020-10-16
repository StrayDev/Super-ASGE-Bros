#pragma once
#include "game/gameobjects/gameobject.h"
#include "factory.h"

class BlockFactory : public Factory
{
public:
    static void createTitleCard();
    static GameObject* createBlock(int i);

private:
};


