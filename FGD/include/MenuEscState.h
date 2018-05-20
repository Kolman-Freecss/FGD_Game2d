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
    BITMAP *options;
    BITMAP *options_pressed;
    BITMAP *save_game;
    BITMAP *save_game_pressed;
    BITMAP *menu_initial;
    BITMAP *menu_initial_pressed;
    BITMAP *leave_game;
    BITMAP *leave_game_pressed;
    BITMAP *back_game;
    BITMAP *back_game_pressed;


    void optionsPressed();
    void saveGamePressed();
    void menuPressed();
    void leavePressed();
    void backPressed();

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
