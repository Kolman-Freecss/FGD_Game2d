#ifndef Enemy_h
#define Enemy_h

#include <vector>

#include "Character.h"
#include "Object.h"
#include "String.h"


class Enemy : public Character {

 public:
    Enemy();
    Enemy(BITMAP ***animations, int health, int damage, int speed, int shield, int x, int y, int height, int width);
    //virtual ~Enemy();

 private:
    //int const DAMAGE = 10;
    /**
     * @element-type Object
     */
    std::vector< Object* > loot;
};

#endif // Enemy_h
