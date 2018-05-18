#ifndef Enemy_h
#define Enemy_h

#include <vector>

#include "Character.h"
#include "Object.h"
#include "String.h"
#include <Drawable.h>


class Enemy : public Character {

 public:
    Enemy();
    Enemy(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);
    //virtual ~Enemy();
    /**
    Actualiza tanto la posicion de enemigo(Movimiento) como otros valores
    */
    void update();
    //bool detectionRadiusEnemy(Drawable *drawable);

 private:
     int direction;
     int timeNextRandomize;
     /**
     Simulación inteligencia artificial
     */
     int detectionRadius;

    //int const DAMAGE = 10;
    /**
     * @element-type Object
     */
    std::vector< Object* > loot;


};

#endif // Enemy_h
