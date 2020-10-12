#include "cell.h"

void Cell::assignToCell(int id, GameObject* obj)
{
    block_id = id;
    delete gameobject;
    gameobject = obj;
    gameobject->getComponent<Transform*>()->setPosition(position);
    gameobject->getComponent<SpriteRenderer*>()->setSpriteSize(Vector2(cell_size,cell_size));
}

GameObject* Cell::getGameObject()
{
    if (!gameobject) return nullptr;
    return gameobject;
}






