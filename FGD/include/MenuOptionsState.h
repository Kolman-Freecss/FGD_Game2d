#ifndef MenuOptionsState_h
#define MenuOptionsState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class MenuOptionsState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *background_image;


    BITMAP *music;
    BITMAP *music_pressed;
    BITMAP *music_checked;
    BITMAP *music_pressed_checked;


    BITMAP *easy;
    BITMAP *easy_pressed;
    BITMAP *medium;
    BITMAP *medium_pressed;
    BITMAP *hard;
    BITMAP *hard_pressed;
    BITMAP *backk;
    BITMAP *backk_pressed;


    void musicPressed();
    void difficultyPressed();
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

    MenuOptionsState(GameStateManager *game);



};

#endif // MenuOptionsState_h
