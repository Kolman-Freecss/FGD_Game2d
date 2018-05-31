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

    void genWalkCollision() override;
    void setDirectionEnemy(int direction);
    bool detectionRadiusEnemy(Drawable *drawable);
    Weapon* randomizeDrop();
    int getDetectionRadius();
    void setDetectionRadius(int detectionRadius);
    void dieAnim();


private:
    bool changeDirectionIfCol = false;
     int direction;
     int timeNextRandomize;
     /**
     Simulacion inteligencia artificial
     */
     int detectionRadius;

    std::vector< Object* > loot;


};

#endif // Enemy_h
