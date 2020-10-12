#pragma once

class Vector2
{
public:
    Vector2() = default;
    Vector2(float x, float y) {_x = x; _y = y;}
    ~Vector2() = default;

    Vector2& operator-(const Vector2& rhs);
    Vector2& operator+(const Vector2& rhs);

    float normalised();
    float x() { return _x; }
    float y() { return _y; }

    static float distance(Vector2 pos1, Vector2 pos2);

private:
    float _x = 0;
    float _y = 0;


};


