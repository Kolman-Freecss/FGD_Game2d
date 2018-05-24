#include "Inventory.h"
#include "vector"
#include <Object.h>

using namespace std;

Inventory::Inventory()
{

    this->currentMoney = 20;
}

int Inventory::getMaxObjects() {
    return maxObjects;
}

void Inventory::setMaxObjects(int maxObjects) {
    Inventory::maxObjects = maxObjects;
}

int Inventory::getMaxCurrentObjects() {
    return maxCurrentObjects;
}

void Inventory::setMaxCurrentObjects(int maxCurrentObjects) {
    Inventory::maxCurrentObjects = maxCurrentObjects;
}

int Inventory::getMaxMoney() {
    return maxMoney;
}

void Inventory::setMaxMoney(int maxMoney) {
    Inventory::maxMoney = maxMoney;
}

int Inventory::getCurrentMoney() {
    return this->currentMoney;
}

void Inventory::setCurrentMoney(int currentMoney) {
    Inventory::currentMoney = currentMoney;
}

vector<Object *>* Inventory::getObjectListPtr() {
    /*int size1 = this->objectList.size();
    this->objectList.push_back(new Object());
    int size2 = this->objectList.size();*/
    return &objectList;
}

vector<Object *> Inventory::getObjectList() {
    return objectList;
}

void Inventory::setObjectList(vector<Object *> &objectList) {
    Inventory::objectList = objectList;
}

