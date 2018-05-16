#ifndef MenuInitialState_h
#define MenuInitialState_h

#include <GameState.h>

using namespace std;

class MenuInitialState : public GameState{

 public:

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
