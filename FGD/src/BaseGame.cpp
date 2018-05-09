#include <BaseGame.h>
#include <vector>
#include <DAOMap.h>
#include <allegro.h>
using namespace std;

BaseGame::BaseGame()
{
    DAOMap managerMaps = DAOMap();
    this->activeMap = managerMaps.getMap(0);
}

void BaseGame::chargeGame()
{

     /*allegro_init();
     install_keyboard();

     clear_to_color(buffer, 0xaaaaaa);
    set_color_depth(24);

     //set_color_depth(32);
     set_gfx_mode(GFX_AUTODETECT_WINDOWED, SIZE_WINDOW_X, SIZE_WINDOW_Y, 0, 0);

     // si no encuentrusing std::cout;a la imagen peta del todo XD
     this->buffer = create_bitmap(SIZE_WINDOW_X, SIZE_WINDOW_Y);*/





    BITMAP** matrixAnimationsPlayer;
    matrixAnimationsPlayer = new BITMAP*[1];
    for(int i = 0; i < 1; i++){
        matrixAnimationsPlayer[i] = new BITMAP[1];
    }
    BITMAP *bitmapPlayer = load_bitmap("src\\Resources\\Player_Front_With_Sword.bmp",NULL);
    matrixAnimationsPlayer[0][0] = *bitmapPlayer;

    this->player = Player(matrixAnimationsPlayer, 100, 20, 1, 20, 50, 50, 33, 66);

    this->player.keyboard();
}

void BaseGame::update()
{
    //this->chargeGame();
//if el mapa es 1
    this->printGame();


}

void BaseGame::printGame()
{
    Drawable **matrix = this->activeMap.getAmbientMatrix();
    int lengthMatrix = this->activeMap.getSizeOfMatrix();

    //int lengthVectorPointers = sizeof(matrix)/sizeof(*matrix);
    //int *lengthVectorRef = &lengthVectorPointers;

    for(int i = 0; i < lengthMatrix; i++){
        for(int j = 0; j < lengthMatrix; j++){
            BITMAP *bitmapAmbient = matrix[i][j].getBitmapAmbient(); //PETA AQUIIIIIIIII vale estamos cojiendo mal las cosas
                                                                // hay que cojer el vector que hemos rellenado de maps
                                                                // o
                                                                // instanciar el baseGame para que el activegame sea ese map
                                                                // o
                                                                // Estamos usando el get de Drawable
                                                                //o

                                                                //ok ok ok ok ok es lo de abajo definitivo
                                                                // es una matrix de drawables lo rellenamos como drwables
                                                                //y intentamos devolver un bitmap
                                                                // el matrix es de drawables y intentamos recojer un bitmap
            //BITMAP *bitmapPointer = &bitmapAmbient;
            if(i == 0 && j == 0){
                stretch_blit(bitmapAmbient, this->buffer, 0, 0, bitmapAmbient->w, bitmapAmbient->h, 0, 0, this->SIZE_WINDOW_X, this->SIZE_WINDOW_Y);
            }
            else{
                matrix[i][j].draw(this->buffer);
            }
        }
    }

    for(Enemy enemy : this->activeMap.getVectorEnemies()){
        enemy.draw(this->buffer);
    }

    this->player.draw(this->buffer);

    blit(this->buffer, screen, 0, 0, 0, 0, 800, 600);



}
