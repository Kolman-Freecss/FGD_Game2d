#ifndef WinState_h
#define WinState_h

#include <GameState.h>
#include <GameStateManager.h>

using namespace std;

class WinState : public GameState{

 public:

    BITMAP *background_image;

    //BITMAP *mouse = load_bitmap("src\\Resources\\Mouse.bmp",NULL);

    void userPressed();
    void passwordPressed();
    void enterPressed();
    void finishPressed();
    void registerPressed();
    void cruzPressed();

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

    WinState(GameStateManager *game);

 private:



};

#endif // WinState_h
