#include "input.h"
#include <Engine/Logger.hpp>


void Input::get(const ASGE::KeyEvent* key, ASGE::Game* game)
{
    switch (key->key)
    {
        case ASGE::KEYS::KEY_A:
            _left = float(key->action);
            //Logging::log("left");
            break;
        case ASGE::KEYS::KEY_D:
            _right = float(key->action);
            //Logging::log("right");
            break;
        case ASGE::KEYS::KEY_SPACE:
            _jump = float(key->action);
            //Logging::log("jump");
            break;
        case ASGE::KEYS::KEY_ENTER:
            _enter = float(key->action);
            //Logging::log("enter");
            break;
        case ASGE::KEYS::KEY_ESCAPE:
            game->signalExit();
            break;
    }
}


