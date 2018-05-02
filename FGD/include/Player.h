#ifndef Player_h
#define Player_h

#include "Character.h"


class Player : public Character {

 public:
    int newAttr;

 private:
    int level;
    int shield;
};

#endif // Player_h
