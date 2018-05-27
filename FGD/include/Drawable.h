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
    int collisionRadius;

    int x;
    int y;
    int height;
    int width;
    int activeBitmap[2];

 public:
    /**
     * CONSTS TO INDICATE DIRECTIONS
     */
    const static int UP = 0;
    const static int RIGHT = 1;
    const static int DOWN = 2;
    const static int LEFT = 3;

    Drawable();
    Drawable(BITMAP ***animations, int x, int y, int height, int width);
    Drawable(BITMAP *bitmapAmbient, int x, int y, int height, int width);

    Drawable(BITMAP *bitmapAmbient, int x, int y, int width, int height, int colPosX, int colPosY, int colRadius);

    //virtual ~Drawable();

    //getters setters
    int getX();
    int getY();
    int getHeight();
    int getWidth();
    void setHeight(int height);
    void setWidth(int widht);
    void setX(int x);
    void setY(int y);

    //funciones
    virtual void draw(BITMAP *buffer);
    bool attackCollision(Drawable *drawable, Weapon *weapon, int direction);
    void drawAmbient(BITMAP *buffer);
    bool collision(Drawable *drawable);
    int distance(Drawable *drawable);
    BITMAP *getBitmapAmbient();

    virtual void genWalkCollision();


};

#endif // Drawable_h
