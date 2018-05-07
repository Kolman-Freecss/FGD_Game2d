#ifndef Drawable_h
#define Drawable_h
#include <allegro.h>



class Drawable{

 protected:
    //TODO cambiar por matriz
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
    void draw(BITMAP *image, BITMAP *buffer);
    bool CheckCollision(Drawable drawable);
    int distance(Drawable drawable);


};

#endif // Drawable_h
