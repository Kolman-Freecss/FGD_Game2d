#ifndef MenuInventarioState_h
#define MenuInventarioState_h

#include <GameState.h>
#include <GameStateManager.h>
#include <Player.h>

using namespace std;

class MenuInventarioState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *background_image;
    BITMAP *player_image;
    BITMAP *coin_gold;
    BITMAP *pagination_1;
    BITMAP *pagination_2;


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

    MenuInventarioState(GameStateManager *game, Player *player);

 private:
    int pagination = 1;
    int selectedObject = 0;

    void drawPagination();
    void drawObjects();
    void drawStatsPlayer();
    void drawCharacteristicsSelectedWeapon();
    void drawMoney();

    Player *playerInventory;



};

#endif // MenuOptionsState_h
