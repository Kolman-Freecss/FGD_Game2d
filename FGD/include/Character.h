#ifndef Character_h
#define Character_h

#include "Drawable.h"
#include <allegro.h>
#include <vector>

using namespace std;

class Character : public Drawable{

protected:
    int speed;
    int damage;
    int health;
    int shield;
    int ax;
    int ay;
    bool isAttacking;
    Weapon *selectedWeapon;
    bool isAlive;


    /**
     * 0 UP
     * 1 RIGHT
     * 2 DOWN
     * 3 LEFT
     */
    int direction;


 public:
    Character();
    Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);

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


    void wounded(Character *attackingCharacter);

    void attackUPanim();
    void attackDOWNanim();
    void attackRIGHTanim();
    void attackLEFTanim();

    bool isIsAlive();

    void setIsAlive(bool isAlive);

    int getDamage();

    void setDamage(int damage);

    int getHealth();

    void setHealth(int health);

    int getShield();

    void setShield(int shield);

    int getDirection();

    void setDirection(int direction);

    Weapon *getSelectedWeapon() const;

    void setSelectedWeapon(Weapon *selectedWeapon);


};

#endif // Character_h
