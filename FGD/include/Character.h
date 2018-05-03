#ifndef Character_h
#define Character_h

#include "Drawable.h"

class Character : public Drawable{


 protected:
    int speed;
    int damage;
    int health;
    int shield;

 public:
    Character();
    //virtual ~Character();
    int getSpeed();

};

#endif // Character_h
