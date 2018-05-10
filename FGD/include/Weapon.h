#ifndef Weapon_h
#define Weapon_h

#include "Object.h"


class Weapon : public Object {


    protected:
        int attackDistance;
    public:
        Weapon();
        int getAttackDistance();

};

#endif // Weapon_h
