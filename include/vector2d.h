#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D
{
    double x;
    double y;

    Vector2D(double x = 0, double y = 0);

    static const Vector2D up;
    static const Vector2D down;
    static const Vector2D left;
    static const Vector2D right;

    void operator+= (const Vector2D &other);
    void operator-= (const Vector2D &other);
    void operator*= (double coefficient);
    void operator/= (double coefficient);
};

const Vector2D operator+ (const Vector2D &vec1, const Vector2D &vec2);
const Vector2D operator- (const Vector2D &vec1, const Vector2D &vec2);
const Vector2D operator* (const Vector2D &vec, const double coefficient);
const Vector2D operator/ (const Vector2D &vec, const double coefficient);

bool operator ==(const Vector2D &vec1, const Vector2D &vec2);

#endif // VECTOR2D_H
