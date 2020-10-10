#include <game/components/transform.h>
#include "gameobject.h"

GameObject::GameObject()
{
    components.push_back(new Transform(this));
}
