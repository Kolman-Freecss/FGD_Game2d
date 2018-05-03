#include <allegro.h>
#include <iostream>
#include <istream>
#include <vector>
using std::cout;
#include <Player.h>

int main()
{
         const int SIZE_WINDOW_X = 800;
         const int SIZE_WINDOW_Y = 600;

 allegro_init();
 install_keyboard();

 set_color_depth(32);
 set_gfx_mode(GFX_AUTODETECT_WINDOWED, SIZE_WINDOW_X, SIZE_WINDOW_Y, 0, 0);

 // si no encuentrusing std::cout;a la imagen peta del todo XD
 BITMAP *buffer = create_bitmap(SIZE_WINDOW_X, SIZE_WINDOW_Y);
 //una imagen de 24 biiiitss
 //BITMAP *prota[] = {load_bmp("Sprite_1_1.bmp",NULL), load_bmp("Sprite_1_2.bmp", NULL), load_bmp("Sprite_1_3.bmp", NULL)};
 BITMAP *prota  = load_bmp("src\\Resources\\Sprite1.bmp",NULL);
 /*BITMAP *protas2 = load_bmp("Sprite_1_2.bmp", NULL);
 BITMAP *protas3 = load_bmp("Sprite_1_3.bmp", NULL);*/
 //To do .. Comprovar si esta bien la ruta
 BITMAP *fondo  = load_bmp("src\\Resources\\grass.bmp",NULL);
 //stretch_blit(fondo, buffer, 0, 0, fondo->w, fondo->h, 0, 0, buffer->w, buffer->h);


 /*if(&prota == 0){
    cout << "null";
 }*/

 bool salir;
 int x,y;

 // inicializar vbles
 x = 10;
 y = 10;
 salir = false;

clear_to_color(buffer, 0xaaaaaa);
set_color_depth(24);
//Resize image
//stretch_blit(fondo, buffer, 0, 0, fondo->w, fondo->h, 0, 0, SIZE_WINDOW_X, SIZE_WINDOW_Y);

int animacion = 0;


Player player;


 while ( !salir )
 {
            stretch_blit(fondo, buffer, 0, 0, fondo->w, fondo->h, 0, 0, SIZE_WINDOW_X, SIZE_WINDOW_Y);
          //clear_to_color(buffer, 0xaaaaaa);
          masked_blit(fondo, buffer, 0,0, 50, 50, SIZE_WINDOW_X,SIZE_WINDOW_Y);
          masked_blit(prota, buffer, 0,0, player.getX(), player.getY(), 32,32);

          player.keyboard();
          //Devuelve bien
          //cout << posicion.getX();

          // teclas control usuario
          /*if ( key[KEY_UP] )
          {
              if(animacion < 3){
                masked_blit(prota[animacion], buffer, 0,0, x, y, 32,32);
                animacion+=1;
              }else{
                animacion = 0;
                masked_blit(prota[0], buffer, 0,0, x, y, 32,32);
              }
               y--;
          }
          if ( key[KEY_DOWN] )
          {
              //masked_blit(prota[1], buffer, 0,0, x, y, 32,32);
               y++;
          }
          if ( key[KEY_LEFT] )
          {
              //masked_blit(prota[2], buffer, 0,0, x, y, 32,32);
               x--;
          }
          if ( key[KEY_RIGHT] )
          {
              //masked_blit(prota[2], buffer, 0,0, x, y, 32,32);
               x++;
          }

          // limites
          if ( x < 0 ) x = 0;
          if ( x > 800 ) x = 800;
          if ( y < 0 ) y = 0;
          if ( y > 600 ) y = 600;*/


       blit(buffer, screen, 0, 0, 0, 0, 800, 600);
        //cout << "hola";
       rest(10);

       // tecla de salida
       if ( key[KEY_ESC] ) salir = true;

    }

//for(int i= 0; i < 3; i++){
 destroy_bitmap(prota);
//}
 destroy_bitmap(fondo);
 destroy_bitmap(buffer);

 return 0;
}
END_OF_MAIN();