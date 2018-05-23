#include "Weapon.h"
#include <Object.h>

/*Weapon::Weapon(){

}*/

Weapon::Weapon(int attackDistance, int damage, BITMAP *imageOfObject, int width, int height):
        Object(imageOfObject, width, height){
    this->attackDistance = attackDistance;
    this->damage = damage;
}

int Weapon::getAttackDistance(){
    return this->attackDistance;
}


void Weapon::setAttackDistance(int attackDistance) {
    Weapon::attackDistance = attackDistance;
}

int Weapon::getDamage() {
     return damage;
}

void Weapon::setDamage(int damage) {
    Weapon::damage = damage;
}


