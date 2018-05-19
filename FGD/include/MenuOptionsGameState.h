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
    BITMAP *music;
    BITMAP *music_pressed;
    BITMAP *music_check;
    BITMAP *music_pressed_check;
    BITMAP *returnn;
    BITMAP *return_pressed;

    void musicPressed();
    void returnPressedF();

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
