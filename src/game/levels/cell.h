#pragma once
#include "game/math/vector2.h"
#include "game/gameobjects/gameobject.h"
#include "game/components/transform.h"
#include "game/components/spriterenderer.h"

class Cell
{
public:
    Cell(float size, Vector2 pos) { cell_size = size; position = pos; }
    ~Cell() = default;

    void assignToCell(int id, GameObject* obj);

    bool isOccupied() { return gameobject; }
    Vector2 getPosition() { return position; }
    GameObject* getGameObject();

private:
    float cell_size = 0;
    int block_id = 0;
    Vector2 position;
    GameObject* gameobject = nullptr;
};


