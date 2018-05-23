#include "Inventory.h"
#include "vector"

using namespace std;

Inventory::Inventory()
{
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
    return currentMoney;
}

void Inventory::setCurrentMoney(int currentMoney) {
    Inventory::currentMoney = currentMoney;
}

vector<Object *> Inventory::getObjectList() {
    return objectList;
}

void Inventory::setObjectList(const std::vector<Object *> &objectList) {
    Inventory::objectList = objectList;
}

