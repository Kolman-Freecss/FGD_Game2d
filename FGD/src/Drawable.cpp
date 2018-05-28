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
    //this->collisionRadius = (width/3)*2;
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

Drawable::Drawable(BITMAP *bitmapAmbient, int x, int y, int height, int width, int colPosX, int colPosY, int colRadius, int coltype) {
    this->bitmapAmbient = bitmapAmbient;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->walkCollision[0] = colPosX;
    this->walkCollision[1] = colPosY;
    this->collisionType = coltype;
    this->collisionRadius = colRadius;
}


void Drawable::draw(BITMAP *buffer){
    try {
        //BITMAP *bitmapAnimation = this->animations[4][2];

        BITMAP *bitmapAnimation = this->animations[activeBitmap[0]][activeBitmap[1]];
        masked_blit(bitmapAnimation, buffer, 0, 0, x, y, width, height);
    }catch (exception& e){
        cout << "petada" << endl;
    }
}

void Drawable::drawAmbient(BITMAP *buffer){
        masked_blit(this->bitmapAmbient, buffer, 0, 0, x, y, width, height);
}

bool Drawable::attackCollision(Drawable *drawable, Weapon *weapon, int direction) {

    //TODO cambiar 100 por weapon->getAttackDistance()
    if (distance(drawable)< 100){

        float angle = atan2(this->y - drawable->y, this->x - drawable->x) *180/3.14;
        float percent = 90;
        float endAngle;
        float startAngle = 0;

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
        case 1:{//circular
            if (distance(drawable) < (this->collisionRadius + drawable->collisionRadius)) {
                return true;
            }
            break;
        }
        case 2: {//cuadrada

            int DeltaX = this->x + this->walkCollision[0] - max(drawable->x, min(this->x + this->walkCollision[0], drawable->x + drawable->width-(drawable->width/10)));
            int DeltaY = this->y + this->walkCollision[1] - max(drawable->y, min(this->y + this->walkCollision[1], drawable->y + drawable->height));
            if ((DeltaX * DeltaX + DeltaY * DeltaY) < (this->collisionRadius * this->collisionRadius)){
                return true;
            }
            break;
        }

        case 3:{

            int DeltaX2 = this->x + this->walkCollision[0] - max(drawable->x+drawable->walkCollision[0], min(this->x + this->walkCollision[0], drawable->x+drawable->walkCollision[0] + drawable->width-drawable->walkCollision[0]));
            int DeltaY2 = this->y + this->walkCollision[1] - max(drawable->y+drawable->walkCollision[1], min(this->y + this->walkCollision[1], drawable->y+drawable->walkCollision[1] + drawable->height-drawable->walkCollision[1]));
            if ((DeltaX2 * DeltaX2 + DeltaY2 * DeltaY2) < (this->collisionRadius * this->collisionRadius)){
                return true;
            }

            break;
        }
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

//TODO BORRAR
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



