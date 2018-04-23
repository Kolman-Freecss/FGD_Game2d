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
    Object loot;
    String String;

 public:

    /**
     * @element-type 
     */
     *my;

    /**
     * @element-type String
     */
    String *myString;

 private:

    /**
     * @element-type Object
     */
    std::vector< Object* > loot;

    /**
     * @element-type String
     */
    std::vector< String* > String;
};

#endif // Enemy_h
