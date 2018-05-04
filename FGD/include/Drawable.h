#ifndef Drawable_h
#define Drawable_h
#include <allegro.h>



class Drawable{

 protected:

    int x;
    int y;
    int height;
    int width;


 public:
    Drawable();
    //virtual ~Drawable();
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    void printSprite(BITMAP *image, BITMAP *background, int source_x, int source_y, int dest_x, int dest_y, int width, int height);





};

#endif // Drawable_h
