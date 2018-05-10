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
    //Character(BITMAP **animations, int health);
    Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);
    //virtual ~Character();
    int getSpeed();

};

#endif // Character_h
