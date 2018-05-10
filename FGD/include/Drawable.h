#ifndef Drawable_h
#define Drawable_h
#include <allegro.h>



class Drawable{

 protected:
    BITMAP ***animations;
    BITMAP *bitmapAmbient;
    int x;
    int y;
    int height;
    int width;
    int activeBitmap[2];

 public:
    Drawable();
    Drawable(BITMAP ***animations, int x, int y, int height, int width);
    Drawable(BITMAP *bitmapAmbient, int x, int y, int height, int width);
    //virtual ~Drawable();
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    void setHeight(int height);
    void setWidth(int widht);
    void setX(int x);
    void setY(int y);
    //void printSprite(BITMAP *image, BITMAP *buffer, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
    void draw(BITMAP *buffer);
    bool checkCollision(Drawable drawable);
    int distance(Drawable drawable);
    BITMAP *getBitmapAmbient();




};

#endif // Drawable_h
