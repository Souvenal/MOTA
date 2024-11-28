#include "cordinate.h"

int Cordinate::block_length = WINDOW_SIZE_H / ROW_NUM;

QRectF Cordinate::GetRect(Vector2D pos)
{
    int left = WINDOW_SIZE_W -
               block_length * (COL_NUM - pos.x + 1);
    int top = WINDOW_SIZE_H - block_length * pos.y;
    return QRectF(left, top, block_length, block_length);
}
