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

 // inicializar vbles
 salir = false;

BaseGame myGame = BaseGame();

 while ( !salir )
 {

          myGame.update();


          //player.keyboard();



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
