#pragma once
#include <vector>
#include <Engine/Sprite.h>
#include <Engine/Renderer.h>
#include <game/math/vector2.h>

class GameObject
{
public:
    GameObject() = default;
    ~GameObject() = default;

    ASGE::Sprite* getSprite() { return _sprite; }
    float getWidth() const { return _width; }

    void setSprite(ASGE::Renderer* renderer, std::string file_path);
    void setPosition(float x, float y);
    void setPosition(Vector2 pos);

    Vector2 getPosition() { return _position; };

protected:
    float _x = 0;
    float _y = 0;
    float _width = 0;

    Vector2 _position = Vector2();
    ASGE::Sprite* _sprite = nullptr;
};


