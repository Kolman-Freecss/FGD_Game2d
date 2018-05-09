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

 const int SIZE_WINDOW_X = 800;
    const int SIZE_WINDOW_Y = 600;
     allegro_init();
     install_keyboard();


    set_color_depth(24);

     //set_color_depth(32);
     set_gfx_mode(GFX_AUTODETECT_WINDOWED, SIZE_WINDOW_X, SIZE_WINDOW_Y, 0, 0);

     // si no encuentrusing std::cout;a la imagen peta del todo XD
     BITMAP *buffer = create_bitmap(SIZE_WINDOW_X, SIZE_WINDOW_Y);

     clear_to_color(buffer, 0xaaaaaa);



BaseGame *myGame = new BaseGame();

myGame->chargeGame();

 while ( !salir )
 {

          myGame->update();


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
