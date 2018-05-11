#include "Character.h"
#include "Drawable.h"

Character::Character()
{
}

/*Character::Character(BITMAP **animations, int health)
{
    this->animations = animations;
    this->health = health;
}*/

Character::Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
                    Drawable(animations, x, y, height, width)
{
    this->health = health;
    this->damage = damage;
    this->speed = speed;
    this->shield = shield;
}

int Character::getSpeed()
{
    return this->speed;
}

int Character::getAX(){
    return this->ax;
}
int Character::getAY(){
    return this->ay;
}

void Character::walkUP(){
    this->ay = y;
    this->y-= this->speed;
    walkUPanim();
}
void Character::walkDOWN(){
    this->ay = y;
    this->y+= this->speed;
    walkDOWNanim();
}
void Character::walkRIGHT(){
    this->ax = x;
    this->x+= this->speed;
    walkRIGHTanim();
}
void Character::walkLEFT(){
    this->ax = x;
    this->x-= this->speed;
    walkLEFTanim();
}

void Character::walkUPanim(){

}
void Character::walkDOWNanim(){

}
void Character::walkRIGHTanim(){

}
void Character::walkLEFTanim(){

}
