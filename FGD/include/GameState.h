#ifndef GameState_h
#define GameState_h

#include <GameStateManager.h>
#include <Music.h>
#include <Player.h>

class GameState {

 public:

     GameStateManager *game;
     Music managerMusic = Music();
     Player player;

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

protected:

     void setDifficulty(int difficulty);
     int getDifficulty();
     void setSound(bool sound);
     bool getSound();
     bool leftClick();
     bool keyI();

     char* generalKeyboard();

 private:

    static int difficulty;
    static bool sound;
    static int timeClicked;
    static int timePress;


};

#endif // GameState_h
