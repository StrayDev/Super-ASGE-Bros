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
    ~GameObject();

    void addComponent(Component* _component);

    template <typename T> //need to figure out how to put this in its own header .tpp i think?
    T getComponent()
    {
        for(auto c : components)
        {
            if (dynamic_cast<T>(c))
            {
                return reinterpret_cast<T>(c);
            }
        }
        return nullptr;
    }

    static std::vector<GameObject*> getAllObjects() { return all_objects; }
    static void destroyAllObjects();
    static void destroyNonPersistentObjects();
    static std::vector<GameObject*> all_objects;

protected:
    std::vector<Component*> components;


};


