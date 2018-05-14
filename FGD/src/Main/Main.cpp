#include <allegro.h>
#include <iostream>
#include <istream>
#include <vector>
using std::cout;
#include <Player.h>
#include <BaseGame.h>

int main()
{
    bool salir;

    salir = false;

    /**
    Inicializamos el allegro
    */
    allegro_init();
    install_keyboard();


    int difficultGame = 1;
    BaseGame *myGame = new BaseGame(difficultGame);

    /**
    Datos que se cargaran antes de empezar el juego ya que seran siempre igual independientemente de
    el nivel/mapa en el que te encuentres
    */
    myGame->chargeGame();

     while ( !salir )
    {

        myGame->update();


        rest(10);

        // tecla de salida
        if ( key[KEY_ESC] ) salir = true;

    }

    //destroy_bitmap(prota);
    //destroy_bitmap(fondo);
    // destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN();
