#include "Player.h"
#include <allegro.h>

Player::Player()
{
}



void Player::keyboard()
{
    if ( key[KEY_UP] )
          {
               this->y--;
          }
          if ( key[KEY_DOWN] )
          {
               this->y++;
          }
          if ( key[KEY_LEFT] )
          {
               this->x--;
          }
          if ( key[KEY_RIGHT] )
          {
               this->x++;
          }

          // limites
          if ( this->x < 0 ) this->x = 0;
          if ( this->x > 800 ) this->x = 800;
          if ( this->y < 0 ) this->y = 0;
          if ( this->y > 600 ) this->y = 600;
}
