#include <allegro.h>
#include "Drawable.h"

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

bool Drawable::checkCollision(Drawable drawable){
    //comprobar tipo colision (cuadrada o circular)
    /*switch (){
        case :
            break;
        case :
            break;
        default:
    }*/
    return true;
}

int Drawable::distance(Drawable drawable){
    //calculo colision
    return 0;
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


