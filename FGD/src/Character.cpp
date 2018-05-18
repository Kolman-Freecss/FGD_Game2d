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
    walkUPanim();
}
void Character::walkDOWN(){
    this->direction = DOWN;
    this->ay = y;
    this->y+= this->speed;
    walkDOWNanim();
}
void Character::walkRIGHT(){
    this->direction = RIGHT;
    this->ax = x;
    this->x+= this->speed;
    walkRIGHTanim();
}
void Character::walkLEFT(){
    this->direction = LEFT;
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
    if (!isAttacking) {

        this->isAttacking = true;

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

void Character::wounded(Character *attackingCharacter) {
    int totalDamage = attackingCharacter->damage + attackingCharacter->selectedWeapon->getDamage();
    if (this->shield - totalDamage < 0){
        totalDamage -= this->shield;
        this->shield = 0;
        this->health -= totalDamage;

    }else{
        this->shield -= totalDamage;
    }

    //TODO evento a check vida
    if (this->health <=0){
        //funcion que mata al character
        isAlive = false;
    }
}

int Character::getDamage(){
    return damage;
}

bool Character::isIsAlive() {
    return false;
}

void Character::setIsAlive(bool isAlive) {

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


Weapon *Character::getSelectedWeapon() const {
    return selectedWeapon;
}

void Character::setSelectedWeapon(Weapon *selectedWeapon) {
    Character::selectedWeapon = selectedWeapon;
}
