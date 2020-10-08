#pragma once
#include "gameobject.h"

class Block : public GameObject
{
public:
    Block(ASGE::Renderer* renderer, int block_id);
    ~Block() = default;

    void setSize(float size);

private:
    int _id = 0;
    std::string folder_path = "data/tileset/";

    std::string selectTexture(int id);
};


