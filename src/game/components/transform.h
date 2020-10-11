#pragma once
#include "component.h"

class Transform : public Component
{
public:
    Transform() = default;
    ~Transform() override = default;

    void init(GameObject *_gameobject) override;

    Vector2 getPosition() { return position; }
    void setPosition(Vector2 pos);
    void setPosition(float _x, float _y) { setPosition(Vector2(_x, _y)); }

private:
    float x = 0;
    float y = 0;
    Vector2 position = Vector2(0, 0);

    float width = 0;
    float height = 0;
    Vector2 dimensions = Vector2(0,0);

};


