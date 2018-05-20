#ifndef MenuEscState_h
#define MenuEscState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class MenuEscState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *background_image;
    BITMAP *new_game;
    BITMAP *new_game_pressed;
    BITMAP *options;
    BITMAP *options_pressed;
    BITMAP *menu_initial;
    BITMAP *menu_initial_pressed;

    void newGamePressed();
    void optionsPressed();
    void menuPressed();

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

    MenuEscState(GameStateManager *game);



};

#endif // MenuEscState_h
