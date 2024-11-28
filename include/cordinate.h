#ifndef CORDINATE_H
#define CORDINATE_H

#include "global.h"

class Cordinate
{
    static int block_length;
public:
    //   y
    //   ^
    //   |
    //   |
    //   |
    //   |
    // (1,1)--------> x
    static QRectF GetRect(Vector2D pos);
};

#endif // CORDINATE_H
