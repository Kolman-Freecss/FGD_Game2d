#include "Character.h"

Character::Character()
{
}

Character::Character(BITMAP **animations, int health)
{
    this->animations = animations;
    this->health = health;
}

int Character::getSpeed()
{
    return 0;
}
