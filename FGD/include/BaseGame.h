#ifndef BaseGame_h
#define BaseGame_h

#include <Map.h>
#include <vector>
#include <Enemy.h>
#include <Player.h>
#include <GameState.h>
#include <DAOMap.h>
#include <Drawable.h>

using namespace std;

class BaseGame : public GameState{

 public:

    /**
    Initial method
    */
    void init();

    void cleanUp();

    void pause(){};
    void resume(){};

    void getEvents();
    void update();
    void draw();
    void drawHUD();
    void drawEnemyHUD(Enemy *enemy);

    Map *activeMap;

    DAOMap *managerMaps;
    BaseGame(int difficult, GameStateManager *game);
    virtual ~BaseGame();



 private:
    /**
    La dificultad que ha elegido el usuario en el Login lo recibe aqui (El constructor lo recibe)
    - 1 = Facil
    - 2 = Medio
    - 3 = Dificil
    */
    int gameDificulty;

    bool bossDetected;


    void artificialIntelligence();
    int directionIA(Enemy *drawable);

    void nextMap();
    void previousMap();
    void winGame();

    void collisionCheck();

    void colPlayerWithEnemies();
    void colPlayerWithAmbient();
    void colEnemies();
    void colEnemiesWithAmbient();
    void colPlayerAndEnemyWithLimits();


    //text
    bool checkTextNpc;




};

#endif // BaseGame_h
