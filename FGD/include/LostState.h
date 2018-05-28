#ifndef LostState_h
#define LostState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class LostState : public GameState{

 public:

    BITMAP *background_image;
    BITMAP *menu_initial;
    BITMAP *menu_initial_pressed;
    BITMAP *charge_game;
    BITMAP *charge_game_pressed;
    BITMAP *leave;
    BITMAP *leave_pressed;

    //BITMAP *mouse = load_bitmap("src\\Resources\\Mouse.bmp",NULL);

    void menuPressed();
    void chargeGamePressed();
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

    LostState(GameStateManager *game);

 private:



};

#endif // LostState_h
