#include "vector2.h"

float Vector2::normalised()
{
    ///not implemented yet
    return 0;
}

Vector2 &Vector2::operator-(const Vector2 &rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;
    return *this;
}

Vector2 &Vector2::operator+(const Vector2 &rhs)
{
    _x += rhs._x;
    _y += rhs._y;
    return *this;}

float Vector2::distance(Vector2 pos1, Vector2 pos2)
{
    auto vector = pos1 - pos2;
    auto distance = vector.x() * vector.x() + vector.y() * vector.y();
    return distance;
}


