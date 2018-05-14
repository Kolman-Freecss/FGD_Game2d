#include "Player.h"
#include <allegro.h>

Player::Player()
{
}

Player::Player(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width):
            Character(animations, health, damage, speed, shield, x, y, height, width)
{


}


void Player::keyboard()
{
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

    // limites
    if ( this->x < 0 ) this->x = 0;
    if ( this->x+this->width > 800 ) this->x = 800-this->width;
    if ( this->y < 0 ) this->y = 0;
    if ( this->y+this->height > 600 ) this->y = 600-this->height;
}
