#ifndef Player_h
#define Player_h

#include "Character.h"


class Player : public Character {

 public:
    Player();
    Player(BITMAP **animations, int health, int damage, int speed, int shield, int x, int y, int height, int width);
    //virtual ~Player();
    void keyboard();

 private:
    int level;
    int shield;
};

#endif // Player_h
