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
    int ax;
    int ay;
    bool isAttacking;


 public:
    Character();
    //Character(BITMAP **animations, int health);
    Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);
    //virtual ~Character();
    int getSpeed();
    int getAX();
    int getAY();

    void walkUP();
    void walkDOWN();
    void walkRIGHT();
    void walkLEFT();

    void walkUPanim();
    void walkDOWNanim();
    void walkRIGHTanim();
    void walkLEFTanim();

    void attack();
    bool getIsAttacking();
    void setIsAttacking(bool op);

    void attackUPanim();
    void attackDOWNanim();
    void attackRIGHTanim();
    void attackLEFTanim();


};

#endif // Character_h
