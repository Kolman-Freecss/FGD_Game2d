#include "Enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
            Character(animations, health, damage, speed, shield, x, y, height, width)
{



}

void Enemy::update()
{
/*
Se podria hacer un switch pero no lo hago por tema de que quiero mirar el rollo de "estado" de un NPC al crearlo
*/

    /**
    Randomiza una direccion del 0 al 3
    0 = abajo
    1 = izquierda
    2 = derecha
    3 = arriba
    */
    if(this->timeNextRandomize % 200 == 0){
        this->direction = rand()%4;
    }

    /**
    Posiciones anteriores por tema colisiones
    */
    int ax = this->x;
    int ay = this->y;

    if(this->direction == 0)
    {
        y++;
    }
    if(this->direction == 1)
    {
        x--;
    }
    if(this->direction == 2)
    {
        x++;
    }
    if(this->direction == 3)
    {
        y--;
    }

    if ( this->x < 0 ) this->x = ax;
    if ( this->x+this->width > 800 ) this->x = ax;
    if ( this->y < 0 ) this->y = ay;
    if ( this->y+this->height > 600 ) this->y = ay;

    this->timeNextRandomize++;

}
