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
