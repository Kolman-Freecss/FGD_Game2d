#include "Drawable.h"
#include <allegro.h>

Drawable::Drawable()
{
    x = 10;
    y = 10;
}

void Drawable::printSprite
(BITMAP *image, BITMAP *background, int source_x, int source_y, int dest_x, int dest_y, int width, int height)
{
        masked_blit(image, background, source_x, source_y, dest_x, dest_y, width, height);
}

int Drawable::getX()
{
    return x;
}

int Drawable::getY()
{
    return y;
}

int Drawable::getHeight()
{
    return 0;
}

int Drawable::getWidth()
{
    return 0;
}


