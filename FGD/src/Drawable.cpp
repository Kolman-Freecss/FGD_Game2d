#include "Drawable.h"
#include <allegro.h>

Drawable::Drawable()
{
    x = 10;
    y = 10;
}

Drawable::Drawable(){

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

void Drawable::draw(BITMAP *image, BITMAP *buffer){
        masked_blit(image, buffer, 0, 0, x, y, width, height);
}

bool Drawable::checkCollision(Drawable drawable){
    //comprobar tipo colision (cuadrada o circular)
    switch (){
        case :
            break;
        case :
            break;
        default:
    }
}

int Drawable::distance(Drawable drawable){
    //calculo colision
}





