#ifndef Potion_h
#define Potion_h

#include "Object.h"


class Potion : public Object {


 private:
    int numUses;
    int damageBoost;
    int healthBoost;
    int shieldBoost;
    int dodgeBoost;
    int restoreHealth;
    int restoreShield;
    int inventoryBoost;
};

#endif // Potion_h
