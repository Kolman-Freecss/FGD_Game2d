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

void Character::attackUPanim() {
    //TODO
        //averiguar como saver cuantas animaciones  hay en la posicion
        if (activeBitmap[1]) {
            activeBitmap[1] = activeBitmap[1]++;

        }else{
            activeBitmap[1] = 0;
            isAttacking = false;
        }



}

void Character::attackDOWNanim() {

}

void Character::attackRIGHTanim() {

}

void Character::attackLEFTanim() {

}

bool Character::getIsAttacking() {
    return isAttacking;
}

void Character::setIsAttacking(bool op) {
    this->isAttacking = op;
}

void Character::attack() {
    this->isAttacking = true;

    switch (activeBitmap[0]) {
        case 1: attackUPanim();
            break;
        case 2: attackRIGHTanim();
            break;
        case 3: attackDOWNanim();
            break;
        case 4: attackLEFTanim();
            break;
            default:;
    }

}
