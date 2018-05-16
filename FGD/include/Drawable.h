#ifndef Drawable_h
#define Drawable_h
#include <allegro.h>
#include <Weapon.h>
#include <cmath>
#include "math.h"
#include "Weapon.h"


class Drawable{

 protected:
    BITMAP ***animations;
    BITMAP *bitmapAmbient;

    //Tipo colision 1=circular 2=cuadrada
    int collisionType;
    int walkCollision[2];
    int weaponCollision[2];
    int collisionRadius;

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

    virtual //void printSprite(BITMAP *image, BITMAP *buffer, int source_x, int source_y, int dest_x, int dest_y, int width, int height);
    void draw(BITMAP *buffer);
    bool attackCollision(Drawable *drawable, Weapon *weapon);
    void drawAmbient(BITMAP *buffer);
    bool collision(Drawable *drawable);
    int distance(Drawable *drawable);
    BITMAP *getBitmapAmbient();

    void genWalkCollision();
    void genAtackCollision();


};

#endif // Drawable_h
