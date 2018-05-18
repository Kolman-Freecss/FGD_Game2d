#include "Weapon.h"

Weapon::Weapon(){

}

Weapon::Weapon(int attackDistance, int damage){
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


