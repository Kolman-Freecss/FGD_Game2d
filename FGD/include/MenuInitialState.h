#ifndef MenuInitialState_h
#define MenuInitialState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class MenuInitialState : public GameState{

 public:

     const static int MIDDLE_SCREEN_X = GameStateManager::SIZE_WINDOW_X / 2;
     const static int MIDDLE_SCREEN_Y = GameStateManager::SIZE_WINDOW_Y / 2;

    BITMAP *logo;
    BITMAP *background_image;
    BITMAP *new_game;
    BITMAP *new_game_pressed;
    BITMAP *options;
    BITMAP *options_pressed;
    BITMAP *leave;
    BITMAP *leave_pressed;
    //BITMAP *mouse = load_bitmap("src\\Resources\\Mouse.bmp",NULL);

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

    MenuInitialState(GameStateManager *game);



};

#endif // MenuInitialState_h
