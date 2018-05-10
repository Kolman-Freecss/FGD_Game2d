#include <allegro.h>
#include "Drawable.h"
#include <cmath>
#include "math.h"
#include "Weapon.h"


Drawable::Drawable()
{
    x = 10;
    y = 10;
}

Drawable::Drawable(BITMAP ***animations, int x, int y, int height, int width)
{
    this->animations = animations;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}

/**
Constructor para instanciar el contenido del Ambiente del mapa
*/
Drawable::Drawable(BITMAP *bitmapAmbient, int x, int y, int height, int width)
{
    this->bitmapAmbient = bitmapAmbient;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
}

void Drawable::draw(BITMAP *buffer){
        //BITMAP bitmapAnimation = this->animations[this->activeBitmap[0]][this->activeBitmap[1]];
        BITMAP* bitmapAnimation = this->animations[0][0];
        //BITMAP *bitmapPointer = &bitmapAnimation;
        masked_blit(bitmapAnimation, buffer, 0, 0, x, y, width, height);
}

//TODO cambiar a character
bool Drawable::atackCollision(Drawable drawable,Weapon weapon){
    if ( distance(drawable) < ( weapon.getAttackDistance() + drawable.collisionRadius ) ) {
            //cout
            return true;
    }
    return false;

}
bool Drawable::collision(Drawable drawable){
    switch(this->collisionType){
        case 1:
            if (distance(drawable)< this->collisionRadius + drawable.collisionRadius){
                return true;
            }
            break;
        case 2:
            break;

        default:;
    }
    return false;

}

int Drawable::distance(Drawable drawable){

    return sqrt((drawable.walkCollision[0]-this->walkCollision[0]) * (drawable.walkCollision[0]-this->walkCollision[0]) +
                     (drawable.walkCollision[1]-this->walkCollision[1]) * (drawable.walkCollision[1]-this->walkCollision[1]));
}




void Drawable::setHeight(int height)
{
    this->height = height;
}

void Drawable::setWidth(int width)
{
    this->width = width;
}

void Drawable::setX(int x)
{
    this->x = x;
}

void Drawable::setY(int y)
{
    this->y = y;
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

BITMAP *Drawable::getBitmapAmbient()
{
    return this->bitmapAmbient;
}


