#pragma once
#include <Engine/OGLGame.h>

class Input
{
public:
    Input() = default;
    ~Input() = default;

    void get(const ASGE::KeyEvent* key, ASGE::Game* game);

    [[nodiscard]] float enter() const { return _enter; }

private:
    float _left = 0;
    float _right = 0;
    float _jump = 0;
    float _enter = 0;
};


