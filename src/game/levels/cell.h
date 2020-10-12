#pragma once

#include "game/math/vector2.h"
#include "game/gameobjects/gameobject.h"

class Cell
{
public:
    explicit Cell(Vector2 pos);
    ~Cell() = default;

    void assignToCell(int id, GameObject* obj);

    bool isOccupied() { return gameobject; }
    Vector2 getPosition() { return position; }
    GameObject* getGameObject();

private:
    int block_id = 0;
    Vector2 position;
    GameObject* gameobject = nullptr;
};


