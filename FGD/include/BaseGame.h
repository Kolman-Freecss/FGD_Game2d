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

    const static int SIZE_WINDOW_X = 800;
    const static int SIZE_WINDOW_Y = 600;
    Map activeMap;
    Player player;
    BaseGame(int difficult);

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
    void createBuffer();





};

#endif // BaseGame_h
