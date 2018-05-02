#ifndef Inventory_h
#define Inventory_h

#include <vector>

class Object;

class Inventory {


 private:
    int maxObjects;
    int maxCurrentObjects;
    int maxMoney;
    int currentMoney;


 private:

    /**
     * @element-type Object
     */
    std::vector< Object* > objectList;
};

#endif // Inventory_h
