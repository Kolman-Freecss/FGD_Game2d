#ifndef Enemy_h
#define Enemy_h

#include <vector>

#include "Character.h"
#include "Object.h"
#include "String.h"

class Object;

class Enemy : public Character {

 public:
    Enemy();
    Enemy(vector<BITMAP> animations, int health);
    //virtual ~Enemy();

 private:
    int const DAMAGE = 10;
    /**
     * @element-type Object
     */
    std::vector< Object* > loot;
};

#endif // Enemy_h
