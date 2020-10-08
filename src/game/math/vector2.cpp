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
