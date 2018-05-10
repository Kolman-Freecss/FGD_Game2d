#ifndef BaseGame_h
#define BaseGame_h

#include <Map.h>
#include <vector>
#include <Enemy.h>
#include <Player.h>

using namespace std;

class BaseGame {

 public:
    const static int SIZE_WINDOW_X = 800;
    const static int SIZE_WINDOW_Y = 600;
    Map activeMap;
    Player player;
    BaseGame();

    //Charge images, sprites, the necessary to start the game
    void chargeGame();
    void update();
    //Print everything on the buffer
    void printGame();

 private:
    BITMAP *buffer;
    void createBuffer();





};

#endif // BaseGame_h
