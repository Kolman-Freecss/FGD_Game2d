#ifndef BaseGame_h
#define BaseGame_h

#include <vector>
#include <Enemy.h>

using namespace std;

class BaseGame {

 public:
    vector<Enemy> enemys;
    vector<BITMAP> enemysBITMAPS;

 private:
    //Charge images, sprites, the necessary to start the game
    void chargeGame();
    void chargeEnemys();
    void refreshGame();
    //Print everything on the buffer
    void printGame();


};

#endif // BaseGame_h
