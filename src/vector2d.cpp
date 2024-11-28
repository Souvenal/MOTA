#include "vector2d.h"

const Vector2D Vector2D::up = Vector2D(0, 1.0);
const Vector2D Vector2D::down = Vector2D(0, -1.0);
const Vector2D Vector2D::left = Vector2D(-1.0, 0);
const Vector2D Vector2D::right = Vector2D(1.0, 0);

Vector2D::Vector2D(double x, double y):
    x(x), y(y)
{}

const Vector2D operator+ (const Vector2D &vec1, const Vector2D &vec2)
{
    return Vector2D(vec1.x + vec2.x, vec1.y + vec2.y);
}

const Vector2D operator- (const Vector2D &vec1, const Vector2D &vec2)
{
    return Vector2D(vec1.x - vec2.x, vec1.y - vec2.y);
}

const Vector2D operator* (const Vector2D &vec, const double coefficient)
{
    return Vector2D(vec.x * coefficient, vec.y * coefficient);
}

const Vector2D operator/ (const Vector2D &vec, const double coefficient)
{
    return Vector2D(vec.x / coefficient, vec.y / coefficient);
}

void Vector2D::operator+= (const Vector2D &other)
{
    x += other.x, y += other.y;
}

void Vector2D::operator-= (const Vector2D &other)
{
    x -= other.x, y -= other.y;
}

void Vector2D::operator*= (const double coefficient)
{
    x *= coefficient, y *= coefficient;
}

void Vector2D::operator/= (const double coefficient)
{
    x /= coefficient, y /= coefficient;
}

bool operator== (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x == vec2.x && vec1.y == vec2.y;
}
