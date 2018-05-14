//
// Created by alumne on 14/05/2018.
//

#include "House.h"
#include <allegro.h>

House::House(BITMAP *bitmapAmbient, int x, int y, int height, int width) : Drawable(bitmapAmbient, x, y, height,
                                                                                    width) {
this->collisionType = 2;
}

void House::draw(BITMAP *buffer) {
    masked_blit(this->bitmapAmbient, buffer, 0, 0, x, y, width, height);
}

