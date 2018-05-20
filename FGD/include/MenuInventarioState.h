#ifndef MenuInventarioState_h
#define MenuInventarioState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class MenuInventarioState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *background_image;
    BITMAP *player;


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

    MenuInventarioState(GameStateManager *game);



};

#endif // MenuOptionsState_h
