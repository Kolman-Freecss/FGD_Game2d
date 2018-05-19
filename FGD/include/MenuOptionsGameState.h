#ifndef MenuOptionsGameState_h
#define MenuOptionsGameState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class MenuOptionsGameState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *background_image;
    BITMAP *new_game;
    BITMAP *new_game_pressed;
    BITMAP *options;
    BITMAP *options_pressed;
    BITMAP *leave;
    BITMAP *leave_pressed;
    /**
    1 = FullScreen
    2 = MiddleScreen
    */
    int fullScreen;

    void newGamePressed();
    void optionsPressed();
    void leavePressed();

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

    MenuOptionsGameState(GameStateManager *game);



};

#endif // MenuOptionsState_h
