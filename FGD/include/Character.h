#ifndef Character_h
#define Character_h

#include "Drawable.h"
#include <allegro.h>
#include <vector>

using namespace std;

class Character : public Drawable{

 private:

protected:
    int speed;
    int damage;
    int health;
    int shield;


 public:
    Character();
    Character(BITMAP **animations, int health);
    Character(BITMAP **animations, int health, int damage, int speed, int shield);
    //virtual ~Character();
    int getSpeed();

};

#endif // Character_h
