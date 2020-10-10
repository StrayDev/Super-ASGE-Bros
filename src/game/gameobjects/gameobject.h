#pragma once
#include <vector>
#include <Engine/Sprite.h>
#include <Engine/Renderer.h>
#include <game/math/vector2.h>

class Component;
class Transform;

class GameObject
{
public:
    GameObject();
    ~GameObject() = default;

    const std::string name = "GameObject";

    void addComponent(Component* _component) { components.push_back(_component); }

protected:
    std::vector<Component*> components;

};


