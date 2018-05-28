#ifndef Player_h
#define Player_h

#include "Character.h"
#include "Inventory.h"
#include <allegro.h>


class Player : public Character {

 public:
    Player();
    Player(BITMAP ***animations, int health, int damage, double speed, int shield, int x, int y, int height, int width);
    //virtual ~Player();
    void keyboard();

    void genWalkCollision() override;

    Inventory* getInventory();

private:
    int experiencia;
    int level;
    int shield;
    Inventory *inventory;

};

#endif // Player_h
