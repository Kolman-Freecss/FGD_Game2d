#ifndef BaseGame_h
#define BaseGame_h

#include <Map.h>
#include <vector>
#include <Enemy.h>
#include <Player.h>
#include <GameState.h>

using namespace std;

class BaseGame : public GameState{

 public:

    void init(){};
    void cleanUp(){};
    void pause(){};
    void resume(){};
    void getEvents(){};
    void draw(){};

    Map activeMap;
    Player player;
    BaseGame(int difficult, GameStateManager *game);

    //Charge images, sprites, the necessary to start the game
    void chargeGame();
    void update();
    //Print everything on the buffer
    void printGame();

 private:
    BITMAP *buffer;
    /**
    La dificultad que ha elegido el usuario en el Login lo recibe aqui (El constructor lo recibe)
    - 1 = Facil
    - 2 = Medio
    - 3 = Dificil
    */
    int difficultGame;


};

#endif // BaseGame_h
