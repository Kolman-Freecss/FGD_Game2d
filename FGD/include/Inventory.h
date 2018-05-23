#ifndef Inventory_h
#define Inventory_h

#include <vector>
#include "Object.h"

using namespace std;

class Inventory {

private:
    /**
    Num que cambia dependiendo del nivel de la bolsa que tengas
    1 = 8
    2 = 16
    3 = 24
    */
    int maxObjects;
    int maxCurrentObjects;
    int maxMoney;
    int currentMoney = 20;
    vector< Object* > objectList;

public:
    Inventory();

    int getMaxObjects();

    void setMaxObjects(int maxObjects);

    int getMaxCurrentObjects();

    void setMaxCurrentObjects(int maxCurrentObjects);

    int getMaxMoney();

    void setMaxMoney(int maxMoney);

    int getCurrentMoney();

    vector<Object *> getObjectList();

    void setCurrentMoney(int currentMoney);

    void setObjectList(const std::vector<Object *> &objectList);


};

#endif // Inventory_h
