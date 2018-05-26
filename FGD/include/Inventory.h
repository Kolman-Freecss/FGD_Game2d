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
    int currentMoney;


public:
    Inventory();
    vector< Object* >* objectList;

    int getMaxObjects();

    void setMaxObjects(int maxObjects);

    int getMaxCurrentObjects();

    void setMaxCurrentObjects(int maxCurrentObjects);

    int getMaxMoney();

    void setMaxMoney(int maxMoney);

    int getCurrentMoney();

    /**
    Un vector que anirá sincronitzat amb el vector de objectes del inventari del player
    */
    vector<int> vectorAttackDistance;
    vector<int> vectorDamage;
    vector<BITMAP*> bitmapsObjects;
    vector<int> vectorWidth;
    vector<int> vectorHeight;

    vector<Object *>* getObjectListPtr();

    void setCurrentMoney(int currentMoney);

    void setObjectList( std::vector<Object *>* &objectList);


};

#endif // Inventory_h
