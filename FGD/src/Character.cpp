#include <Timer.h>
#include <iostream>
#include "Character.h"
#include "Drawable.h"

using namespace std;

/**
 * Constructor vacio
 */
Character::Character()
{
}


/**
 * Contructor basico con los datos necesarios para que se muestre por pantalla
 * @param animations matriz que contiene todas las animaciones del personage
 * @param health
 * @param damage
 * @param speed
 * @param shield
 * @param x
 * @param y
 * @param height
 * @param width
 */
Character::Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
                    Drawable(animations, x, y, height, width)
{
    this->health = health;
    this->damage = damage;
    this->speed = speed;
    this->shield = shield;
    this->alive = true;
    this->ax = x;
    this->ay = y;

    //this->genWalkCollision();
    this->collisionType = 1;

    this->activeBitmap[0] = 0;
    this->activeBitmap[1] = 0;

    this->timeLastAnim = 0;
    this->attackChecked = true;
    this->attacking = false;
}

int Character::getDirection(){
    return direction;
}

void Character::setDirection(int direction) {
    Character::direction = direction;
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
    this->direction = UP;
    this->ay = y;
    this->y-= this->speed;
    walkAnimation();
}
void Character::walkRIGHT(){
    this->direction = RIGHT;
    this->ax = x;
    this->x+= this->speed;
    walkAnimation();
}
void Character::walkDOWN(){
    this->direction = DOWN;
    this->ay = y;
    this->y+= this->speed;
    walkAnimation();
}
void Character::walkLEFT(){
    this->direction = LEFT;
    this->ax = x;
    this->x-= this->speed;
    walkAnimation();
}
void Character::walkAnimation(){
    activeBitmap[0] = direction;
    if (Timer::getTime()-10 > timeLastAnim) {
        timeLastAnim = Timer::getTime();

        switch (direction) {
            case UP:
                walkUPanim();
                break;
            case RIGHT:
                walkRIGHTanim();
                break;
            case DOWN:
                walkDOWNanim();
                break;
            case LEFT:
                walkLEFTanim();
                break;
            default:;
        }
    }
}


void Character::walkUPanim(){
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
    }



}
void Character::walkRIGHTanim(){
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
    }
}

void Character::walkDOWNanim(){
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
    }
}

void Character::walkLEFTanim(){
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
    }
}


void Character::attack() {

        if (Timer::getTime()-10 > timeLastAnim) {
            timeLastAnim = Timer::getTime();
            activeBitmap[0] = direction + 4;//colocar en posicion atacke
            switch (direction) {
                case UP:
                    attackUPanim();
                    break;
                case RIGHT:
                    attackRIGHTanim();
                    break;
                case DOWN:
                    attackDOWNanim();
                    break;
                case LEFT:
                    attackLEFTanim();
                    break;
                default:;
            }
        }


}

void Character::attackUPanim() {
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
        attacking = false;
    }

}
void Character::attackRIGHTanim() {
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
        attacking = false;
    }
}
void Character::attackDOWNanim() {
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
        attacking = false;
    }
}

void Character::attackLEFTanim() {
    if (activeBitmap[1] < 3) {
        activeBitmap[1]++;
    } else {
        activeBitmap[1] = 0;
        attacking = false;
    }
}

bool Character::isAttacking() {
    return attacking;
}

void Character::setAttacking(bool op) {
    this->attacking = op;
}

bool Character::wounded(Character *attackingCharacter) {
    bool v_alive = this->alive;
    int totalDamage = attackingCharacter->damage + attackingCharacter->selectedWeapon->getDamage();
    if (this->shield - totalDamage < 0){
        totalDamage -= this->shield;
        this->shield = 0;
        this->health -= totalDamage;

    }else {
        this->shield -= totalDamage;
    }

    //TODO evento a check vida
    checkAlive();
    if (v_alive == true && alive == false){
        return true;
    }else {
        return false;
    }
}

void Character::checkAlive() {
    if (health <= 0){
        //funcion que mata al character
        alive = false;
    }
}


int Character::getDamage(){
    return damage;
}

bool Character::isIsAlive() {
    return alive;
}

void Character::setIsAlive(bool isAlive) {
    this->alive = isAlive;
}

void Character::setDamage(int damage) {
    Character::damage = damage;
}

int Character::getHealth(){
    return health;
}

void Character::setHealth(int health) {
    Character::health = health;
}

int Character::getShield(){
    return shield;
}

void Character::setShield(int shield) {
    Character::shield = shield;
}


Weapon *Character::getSelectedWeapon(){
    return selectedWeapon;
}

void Character::setSelectedWeapon(Weapon *selectedWeapon) {
    Character::selectedWeapon = selectedWeapon;
}

bool Character::isAttackChecked(){
    return attackChecked;
}

void Character::setAttackChecked(bool endAttack) {
    Character::attackChecked = endAttack;
}

void Character::setXandAX(int posX)
{
    this->x = posX;
    this->ax = posX;
}

void Character::setYandAY(int posY)
{
    this->y = posY;
    this->ay = posY;
}
