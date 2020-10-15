#pragma once
#include <Engine/Camera2D.hpp>
#include <Engine/OGLGame.h>
#include <string>

#include "input.h"

class GameState;

class ASGEGame : public ASGE::OGLGame
{
public:
    explicit ASGEGame(ASGE::GameSettings settings);
    ~ASGEGame() final;
    bool init();

    void setState(GameState* state);
    void setCamera(ASGE::Camera2D camera) { _camera = camera; }

    Input* input() { return _input; }

private:
    void keyHandler(const ASGE::SharedEventData& data);
    void render() override;
    void update(const ASGE::GameTime&) override;

    int key_callback_id   = -1;
    int mouse_callback_id = -1;

    ASGE::Camera2D _camera;
    Input* _input = nullptr;
    GameState* _gameState = nullptr;
};