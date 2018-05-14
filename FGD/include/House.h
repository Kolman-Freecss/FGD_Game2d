#ifndef House_h
#define House_h

#include "Drawable.h"
#include <allegro.h>



class House : public Drawable{

public :
    House(BITMAP *bitmapAmbient, int x, int y, int height, int width);

    void draw(BITMAP *buffer) override;
};


#endif //House_h
