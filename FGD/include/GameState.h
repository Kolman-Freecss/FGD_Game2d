#ifndef GameState_h
#define GameState_h

#include <GameStateManager.h>

class GameState {

 public:

     GameStateManager *game;

     /**
     Initial methods
     */
     virtual void init()=0;
     virtual void cleanUp()=0;

     virtual void pause()=0;
     virtual void resume()=0;

     /**
     Methods Loop
     */
     virtual void getEvents()=0;
     virtual void update()=0;
     virtual void draw()=0;


};

#endif // GameState_h
