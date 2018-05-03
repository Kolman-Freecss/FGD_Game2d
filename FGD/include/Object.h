#ifndef Object_h
#define Object_h

#include "Drawable.h"

class Enemy;
class Inventory;

class Object : public Drawable{

 public:
    int newAttr;

 protected:
    int level;

 public:

    /**
     * @element-type Enemy
     */
    Enemy *myEnemy;

    /**
     * @element-type Inventory
     */
    Inventory *myInventory;
};

#endif // Object_h
