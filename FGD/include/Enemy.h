#ifndef Enemy_h
#define Enemy_h

#include <vector>

#include "Character.h"
#include "Object.h"
#include "String.h"
#include "int.h"

class Object;
class ;
class String;

class Enemy : public Character {

 public:

    virtual int newOperation();

 private:

    /**
     * @element-type Object
     */
    std::vector< Object* > loot;
};

#endif // Enemy_h
