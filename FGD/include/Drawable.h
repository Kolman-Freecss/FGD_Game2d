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
    void setHeight(int height);
    void setWidth(int widht);
    void setX(int x);
    void setY(int y);
    //void printSprite(BITMAP *image, BITMAP *buffer, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
    void draw(BITMAP *image, BITMAP *buffer);
    bool checkCollision(Drawable drawable);
    int distance(Drawable drawable);




};

#endif // Drawable_h
