#ifndef TextState_h
#define TextState_h

#include <GameState.h>
#include <GameStateManager.h>
#include <allegro.h>

using namespace std;

class TextState : public GameState{

 public:

    BITMAP *bocadilloMap1;


    //BITMAP *mouse = load_bitmap("src\\Resources\\Mouse.bmp",NULL);

    void animationBocadilloMap1();


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

    TextState(GameStateManager *game, int callState);

 private:

     vector<char*> vectorBocadillo1Mapa;
     int nextText;
     int secondText;
     //Per mostrar la primera vegada y ya
     bool checkFirstText;
     //Solo se usa una vez
     bool checkNextText;
     //Para el segundo texto
     bool checkSecondText;


     int callState;


};

#endif // TextState_h
