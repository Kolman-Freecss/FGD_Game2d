#ifndef GameStateManager_h
#define GameStateManager_h

#include <vector>
#include <allegro.h>
using namespace std;

class GameState;
class GameStateManager {

 public:
     /**
     Dimensiones pantalla de buffer
     */
    const static int SIZE_WINDOW_X = 800;
    const static int SIZE_WINDOW_Y = 600;


    GameStateManager();
    ~GameStateManager();


    void pushState(GameState *state);
    /**
    Para vaciar el vector de estados al terminar el juego
    */
    void popState();

    /**
    To get the current State in the vector of "states"
    */
    GameState* getCurrentState();

    /**
    Crea la pantalla sobre la que printaremos todos los estados
    */

    void createBuffer();

    /**
    Game loop function & check isRunning
    */
    void gameLoop();
    bool isRunning();
    void setRunning(bool runLoop);

    //void clearUp();
    BITMAP* getBuffer();

 private:
     vector<GameState*> states;
     bool runLoop = true;
     BITMAP *buffer;

    BITMAP *mouse;



};

#endif // GameStateManager_h
