#include <allegro.h>
#include "Drawable.h"
#include <cmath>
#include <iostream>
#include "Weapon.h"
#include <algorithm>

using namespace std;


Drawable::Drawable() {

}
Drawable::Drawable(BITMAP ***animations, int x, int y, int height, int width)
{

    this->animations = animations;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;

   //genWalkCollision();
    this->collisionRadius = (width/3)*2;
    //this->collisionType = 1;
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
    genWalkCollision();
    this->collisionRadius = (width/3)*2;

}


void Drawable::draw(BITMAP *buffer){
        BITMAP* bitmapAnimation = this->animations[0][0];
        masked_blit(bitmapAnimation, buffer, 0, 0, x, y, width, height);
}

void Drawable::drawAmbient(BITMAP *buffer){
        masked_blit(this->bitmapAmbient, buffer, 0, 0, x, y, width, height);
}

bool Drawable::attackCollision(Drawable *drawable, Weapon *weapon, int direction) {

    //cambiar 100 por weapon->getAttackDistance()
    if (distance(drawable)< 100){

        float angle = atan2(this->y - drawable->y, this->x - drawable->x) *180/3.14;
        float percent = 90;
        float endAngle;
        float startAngle = 0;
        //switch (this->activeBitmap[0]) {
                // activeBitmap[0]=1;
        switch (direction) {
            case UP:
                startAngle = 90-percent/2;
                break;
            case RIGHT:
                startAngle = 180-percent/2;
                break;
            case DOWN:
                startAngle = -90-percent/2;
                break;
            case LEFT:
                startAngle = 0-percent/2;
                break;
            default:;
        }
        endAngle = percent + startAngle;
        //calcular si punto dentro de sector circulo
        if (angle >= startAngle && angle <= endAngle) {//calculo normal
            return true;
        }else if ((angle >= startAngle || angle <= startAngle*-1) && direction==RIGHT) {//calculo para derecha
            return true;
        }else {
            return false;
        }

    }

}
bool Drawable::collision(Drawable *drawable){
    switch(drawable->collisionType) {
        case 1://circular
            if (distance(drawable) < (this->collisionRadius + drawable->collisionRadius)) {
                return true;
            }
            break;
        case 2: //cuadrada
            //int DeltaX = this->x + this->walkCollision[0] - max(drawable->x, min(this->x + this->walkCollision[0], drawable->x + drawable->width));

            int DeltaX = this->x + this->walkCollision[0] - max(drawable->x, min(this->x + this->walkCollision[0], drawable->x + drawable->width-(drawable->width/10)));
            int DeltaY = this->y + this->walkCollision[1] - max(drawable->y, min(this->y + this->walkCollision[1], drawable->y + drawable->height));
            if ((DeltaX * DeltaX + DeltaY * DeltaY) < (this->collisionRadius * this->collisionRadius)){
                return true;
            }
            break;

    }
    return false;

}

int Drawable::distance(Drawable *drawable){
    return sqrt(
            ((drawable->x + drawable->walkCollision[0]) - (this->x + this->walkCollision[0]))
            *
            ((drawable->x + drawable->walkCollision[0]) - (this->x + this->walkCollision[0]))
            +
            ((drawable->y + drawable->walkCollision[1]) - (this->y + this->walkCollision[1]))
            *
            ((drawable->y + drawable->walkCollision[1]) - (this->y + this->walkCollision[1])));

}


void Drawable::genWalkCollision(){
    this->walkCollision[0] = this->width/2;
    this->walkCollision[1] = (this->height/6)*5;
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
    return height;
}

int Drawable::getWidth()
{
    return width;
}

BITMAP *Drawable::getBitmapAmbient()
{
    return this->bitmapAmbient;
}



