#ifndef BaseGame_h
#define BaseGame_h

#include <Map.h>
#include <vector>
#include <Enemy.h>
#include <Player.h>
#include <GameState.h>
#include <DAOMap.h>

using namespace std;

class BaseGame : public GameState{

 public:

    /**
    Initial method
    */
    void init();

    void cleanUp(){};

    void pause(){};
    void resume(){};

    void getEvents();
    void update();
    void draw();

    Map activeMap;
    Player player;
    DAOMap managerMaps;
    BaseGame(int difficult, GameStateManager *game);



 private:
    BITMAP *buffer;
    /**
    La dificultad que ha elegido el usuario en el Login lo recibe aqui (El constructor lo recibe)
    - 1 = Facil
    - 2 = Medio
    - 3 = Dificil
    */
    int gameDificulty;

    void artificialIntelligence();
    int directionIA(Enemy *drawable);

    void nextMap();

    void collisionCheck();

    void colPlayerWithEnemies();
    void colPlayerWithAmbient();
    void colEnemies();
    void colEnemiesWithAmbient();


};

#endif // BaseGame_h
