#include "cell.h"
#include <game/components/transform.h>


Cell::Cell(Vector2 pos)
{
    position = pos;
}

void Cell::assignToCell(int id, GameObject* obj)
{
    block_id = id;
    delete gameobject;
    gameobject = obj;
    gameobject->getComponent<Transform*>()->setPosition(position);
}

GameObject* Cell::getGameObject()
{
    if (!gameobject) return nullptr;
    return gameobject;
}






