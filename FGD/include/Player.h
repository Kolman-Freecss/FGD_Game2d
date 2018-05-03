#ifndef Player_h
#define Player_h

#include "Character.h"


class Player : public Character {

 public:
    Player();
    //virtual ~Player();
    void keyboard();

 private:
    int level;
    int shield;
};

#endif // Player_h
