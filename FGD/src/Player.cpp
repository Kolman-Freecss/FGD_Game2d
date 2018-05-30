#include "Player.h"
#include <allegro.h>
#include <iostream>
#include <Inventory.h>
#include <Music.h>

Player::Player()
{
}

Player::Player(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
            Character(animations, health, damage, speed, shield, x, y, height, width)
{
genWalkCollision();
this->collisionRadius = 11;
this->experience = 0;
/**
Le almacenamos la espada en el inventario
*/

this->inventory = new Inventory();
}

void Player::genWalkCollision() {
    //TODO cambiar posicion correcta
    this->walkCollision[0] = 38;
    this->walkCollision[1] = 60;
}

/**
Manejo del teclado del personaje + colision de limites
*/
void Player::keyboard(){
    /**
    * Attack key
    */
    if(key[KEY_SPACE]) {
        if (!attacking) {
            cout << "attacked"<< endl;

            this->attacking = true;
            this->attackChecked = false;
        }
    }

    if ( key[KEY_UP] )
    {
        walkUP();
    }
    if ( key[KEY_DOWN] )
    {
        walkDOWN();
    }
    if ( key[KEY_LEFT] )
    {
        walkLEFT();
    }
    if ( key[KEY_RIGHT] )
    {
        walkRIGHT();
    }


    // limites TODO CAMBIAR A FUNCION
    if ( this->x < 0 ) this->x = 0;
    if ( this->x+this->width > 800 ) this->x = 800-this->width;
    if ( this->y < 0 ) this->y = 0;
    if ( this->y+this->height > 600 ) this->y = 600-this->height;
}




/////////////////////////////              GET & SET                  /////////////////////////

Inventory* Player::getInventory()
{
    return this->inventory;
}

int Player::getExperience() {
    return experience;
}

void Player::setExperience(int experience) {
    Player::experience = experience;
}

int Player::getLevel() {
    return level;
}

void Player::setLevel(int level) {
    Player::level = level;
}

int Player::getShield() {
    return shield;
}

void Player::setShield(int shield) {
    Player::shield = shield;
}
