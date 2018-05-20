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

    Weapon *selectedWeapon;
    bool alive;
    int timeLastAnim;
    bool attacking;
    bool attackChecked;


    /**
     * 0 UP
     * 1 RIGHT
     * 2 DOWN
     * 3 LEFT
     */
    int direction;


 public:
    Character();
    //Character(BITMAP **animations, int health);
    Character(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);
    //virtual ~Character();
    int getSpeed();
    int getAX();
    int getAY();

    void walkUP();
    void walkRIGHT();
    void walkDOWN();
    void walkLEFT();

    void walkAnimation();

    void walkUPanim();
    void walkRIGHTanim();
    void walkDOWNanim();
    void walkLEFTanim();

    void attack();
    bool isAttacking();
    void setAttacking(bool op);

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

    Weapon *getSelectedWeapon();

    void setSelectedWeapon(Weapon *selectedWeapon);

    bool isAttackChecked();

    void setAttackChecked(bool endAttack);


};

#endif // Character_h
